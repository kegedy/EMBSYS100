### EMBSYS100 Assigment 2
<hr>

###### 1. Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program only once to increment “counter”.
  - What is the value of the “counter” from the “Locals” window?
  - What is the value of the “counter” in the “Register” window?
  - Please note if the N and/or V flags are set in the APSR register? Explain why?
  
  **Answer** <br>
  - The value of the counter from the Locals window is -2147483648.
  - The value of the counter in the Register window is 0x80000000 (at register R1).
  - The N and V flags are set to value of 1. N flag indicates a negative condition and V flag indicates an overflow condition.
<hr>

###### 2. If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program once to increment “counter”.
  - What happens to the value of “counter” in the “Locals” window?
  - Please note if the N and/or V flags are set in the APSR register? Explain why?

  **Answer** <br>
  - The value of counter increments by 1 starting at -1 (0XFFFFFFFF) in the Locals window. Counter is incremented 3 times so the final value of counter is 2.
  - The N and V flags are not set. The next value of counter is 0, so there isn't a negative or overflow condition. 
  <hr>
  
###### 3. Change the “counter” variable type in your code to “unsigned”. Inject the values “0x7FFFFFFF” then step thru the program to increment the “counter” once.
  - What is the value of “counter” in the “Locals” window after incrementing for each value?
  - Please note if the N and/or V flags are set in the APSR register? Explain why?

  **Answer** <br>
  - The value of counter in the Locals window is 2147483648 (0x80000000). Since the type is unsigned, the range for counter is 0 to  2^32 -1. Where as the range for int is - 2^31 to 2^31 -1.
  - The N flag is set because it reads if there is a value in bit 31. Since 0x80000000 is equivalent to 0b10000000000000000000000000000001, the N flag is set. The V flag is not set because I have not incremented beyond the upper boundary of counter.
  <hr>
  
  
