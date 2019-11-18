1. Using bit-band region for peripherals:<br><br>
b) What instructions does the compiler produce in assembly for the “writing” to the GPIO bit when using bit-band address?

```
*((unsigned int*)((0x42000000) + (0x20014 * 32) + (5 * 4))) = 0x1;
    0x800'0062: 0x490a         LDR.N     R1, [PC, #0x28]         ; 0x4240'0294
    0x800'0064: 0x2201         MOVS      R2, #1
    0x800'0066: 0x600a         STR       R2, [R1]
```

c) What were the instructions produced when writing to the GPIOx_ODR bit[5] directly?

```
*((unsigned int*)(0x40020000 + 0x14)) |= (1<<5);
    0x800'02b8: 0x480e         LDR.N     R0, [PC, #0x38]         ; GPIOA_ODR
    0x800'02ba: 0x6801         LDR       R1, [R0]
    0x800'02bc: 0xf051 0x0120  ORRS.W    R1, R1, #32             ; 0x20
    0x800'02c0: 0x6001         STR       R1, [R0]
```

2. Create a function with multiple arguments (5 arguments for example) and call that function from within another function. Trace through the assembler and note:<br><br>
a. How does the calling function pass the values to the called function? <br>
The calling function pushes the arguments onto the stack in reverse order. <br><br>

b. What extra code did the compiler generate before calling the function with the multiple arguments? <br>
The compiler pushes registers R2-R8, LR onto the stack. Then it moves a value of 1 into a register corresponding to each parameter passed into the subfunction.
```
main:
        0x64: 0xe92d 0x41fc  PUSH.W    {R2-R8, LR}
    int arg0 = 1;
        0x68: 0x2401         MOVS      R4, #1
    int arg1 = 1;
        0x6a: 0x2501         MOVS      R5, #1
    int arg2 = 1;
        0x6c: 0x2601         MOVS      R6, #1
    int arg3 = 1;
        0x6e: 0x2701         MOVS      R7, #1
    int arg4 = 1;
        0x70: 0xf05f 0x0801  MOVS.W    R8, #1
```

c. What extra code did the compiler generate inside the called function with the multiple list of arguments?<br>
The compiler pushes registers R4-R8, LR onto the stack (total of 14 variables in the stack). Moves value at register R0 into R4. And Loads the address at SP offset by 0x18 into R5. It performs the addition operations and then returns the registers we pushed at the beginning of the funtion.
```
int sum(int arg0, int arg1, int arg2, int arg3, int arg4) {
sum:
         0x40: 0xe92d 0x41f0  PUSH.W    {R4-R8, LR}
         0x44: 0x0004         MOVS      R4, R0
         0x46: 0x9d06         LDR       R5, [SP, #0x18]
    arg5 = arg0;
         0x48: 0x0026         MOVS      R6, R4
    arg6 = arg1;
         0x4a: 0x000f         MOVS      R7, R1
    arg7 = arg2;
         0x4c: 0x4694         MOV       R12, R2
    arg8 = arg3;
         0x4e: 0x469e         MOV       LR, R3
    arg9 = arg4;
         0x50: 0x46a8         MOV       R8, R5
    sum = arg5 + arg6 + arg7 + arg8 + arg9;
         0x52: 0x19b8         ADDS      R0, R7, R6
         0x54: 0xeb1c 0x0000  ADDS.W    R0, R12, R0
         0x58: 0xeb1e 0x0000  ADDS.W    R0, LR, R0
         0x5c: 0xeb18 0x0000  ADDS.W    R0, R8, R0
    return sum;
         0x60: 0xe8bd 0x81f0  POP.W     {R4-R8, PC}
```

d. Any other observations?
