### EMBSYS100 Assigment 2

###### 1. Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program only once to increment “counter”.
  - What is the value of the “counter” from the “Locals” window?
  - What is the value of the “counter” in the “Register” window?
  - Please note if the N and/or V flags are set in the APSR register? Explain why?
  
  **Answer** <br>
- The value of the counter from the Locals window is -2147483648 (0x80000000).<br>
- The value of the counter in the Register window is 0x80000000 (at register R1).<br>
- The N and V flags are set to value of 1. N flag indicates a negative condition and V flag indicates an overflow condition.
<hr>

###### 2. If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program once to increment “counter”.
  - What happens to the value of “counter” in the “Locals” window?
  - Please note if the N and/or V flags are set in the APSR register? Explain why?

  **Answer** <br>
  - The value of counter increments by 1 starting at -1 (0XFFFFFFFF) in the Locals window. Counter is incremented 3 times so the final value of counter is 2.
  - The N and V flags are not set. The next value of counter is 0 so, there isn't a negative or overflow condition. 
  <hr>
  
  
