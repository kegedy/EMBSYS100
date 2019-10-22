### EMBSYS100 Assigment 2
<hr>

###### 1. Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program only once to increment “counter”.
  - The value of the counter from the Locals window is -2147483648.
  - The value of the counter in the Register window is 0x80000000 (at register R1).
  - The N and V flags are set to value of 1. N flag indicates a negative condition and V flag indicates an overflow condition.
<hr>

###### 2. If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program once to increment “counter”.
  - The value of counter starts at value -1 and increments to value 0 in the Locals window.
  - The N and V flags are not set. Since the value of counter is 0, the N flag is not set because it reads bit 31 and the V flag is not set because it reads bit 28.
  <hr>
  
###### 3. Change the “counter” variable type in your code to “unsigned”. Inject the values “0x7FFFFFFF” then step thru the program to increment the “counter” once.
  - The value of counter starts at value 2147483647 and increments to value 2147483648 (0x80000000) in the Locals window. Since the type is unsigned, the range for counter is 0 to  2^32 -1. Where as the range for int is - 2^31 to 2^31 -1.
  - Since 0x80000000 is equivalent to 0b10000000000000000000000000000001, bit 31 is high and the N flag is set. Bit 28 has a value of 0 so the V flag is not set.
  <hr>
  
###### 4. Change the “counter” variable type in your code to “unsigned”. Inject the values “0xFFFFFFFF” then step thru the program to increment the “counter” once.
  - The value of counter starts at value 4294967295 and increments to value 0 in the Locals window.
  - The N and V flags are not set. Since the value of counter is 0, the N flag is not set because it reads bit 31 and the V flag is not set because it reads bit 28.
  <hr>

###### 5. Move the “counter” variable outside of main (at the top of the file).
  - The scope of the counter variable is global.
  - The counter variable is not visible in the Locals view.
  - The counter variable can be tracked in the Statics window.
  - The address of counter in memory is 0x20000000.
  <hr>
  
###### 6. Change the source code to the following, then run the program still in the simulator.
  - The value of counter is 4 at the end of the program.
  - The counter value has changed:
    - Observation 1: `++number` operation is equivalent to increment first and then return number
    - Observation 2: Expand expression `++(*p_int)` to `(*_p_int) = (*_p_int) + 1`
    - Observation 3: `*p_int` points at the memory address (0x20000000) assigned to counter 
    - Using these observations, we know the value at address 0x20000000 is incremented 3 times by `p_int`.
    - Lastly the global variable "counter" increments itself (which also has address 0x20000000).
  <hr>

###### 7. Change the setting of IAR to run the same program on the evaluation board.
  - The counter variable is stored at address 0x20000000.
  - The counter variable is stored as RAM. ROM is read only and is non-volitale such that the data will remain after the program is done running. Modifying the first line from `int counter = 0x0` to `int counter` did not keep the previous value of counter. Therefore counter is stored as RAM. 
  - The value of counter is 4 at the end of the program.
    <hr>
