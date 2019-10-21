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
  - The value of counter starts at value -1 and increments to value 0 in the Locals window.
  - The N and V flags are not set. Since the value of counter is 0, the N flag is not set because it reads bit 31 and the V flag is not set because it reads bit 28.
  <hr>
  
###### 3. Change the “counter” variable type in your code to “unsigned”. Inject the values “0x7FFFFFFF” then step thru the program to increment the “counter” once.
  - What is the value of “counter” in the “Locals” window after incrementing for each value?
  - Please note if the N and/or V flags are set in the APSR register? Explain why?

  **Answer** <br>
  - The value of counter starts at value 2147483647 and increments to value 2147483648 (0x80000000) in the Locals window. Since the type is unsigned, the range for counter is 0 to  2^32 -1. Where as the range for int is - 2^31 to 2^31 -1.
  - Since 0x80000000 is equivalent to 0b10000000000000000000000000000001, bit 31 is high and the N flag is set. Bit 28 has a value of 0 so the V flag is not set.
  <hr>
  
###### 4. Change the “counter” variable type in your code to “unsigned”. Inject the values “0xFFFFFFFF” then step thru the program to increment the “counter” once.
  - What is the value of “counter” in the “Locals” window after incrementing for each value?
  - Please note if the N and/or V flags are set in the APSR register? Explain why?
  
  **Answer** <br>
  - The value of counter starts at value 4294967295 and increments to value 0 in the Locals window.
  - The N and V flags are not set. Since the value of counter is 0, the N flag is not set because it reads bit 31 and the V flag is not set because it reads bit 28.
  <hr>

###### 5. Move the “counter’ variable outside of main (at the top of the file).
  - What is the scope of the variable “counter”?
  - Is it still visible in the “Locals” view?
  - In which window view can we track “counter” now?
  - What is the address of the “counter” variable in memory?
  
  **Answer** <br>
  - The scope of the counter variable is global.
  - The counter variable is not visible in the Locals view.
  - The counter variable can be tracked in the Statics window.
  - The address of counter in memory is 0x20000000.
  <hr>
  
###### 6.
