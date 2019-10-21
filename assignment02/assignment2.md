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

