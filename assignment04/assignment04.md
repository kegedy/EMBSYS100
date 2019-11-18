  Assembly instructions used for writing to the GPIO using bit band addresses.
  ```
  *((unsigned int*)((0x42000000) + (0x20014 * 32) + (5 * 4))) = 0x1;
   0x800'0062: 0x490a         LDR.N     R1, [PC, #0x28]         ; 0x4240'0294
   0x800'0064: 0x2201         MOVS      R2, #1
   0x800'0066: 0x600a         STR       R2, [R1]
   ```
   
    Assembly instructions used for writing to GPIOA_ODR5 directly.
    
