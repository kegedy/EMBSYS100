1. [blink_CMSIS](https://github.com/kegedy/EMBSYS100/tree/dev/assignment06/blink_CMSIS) <br>

2. [control_user_led](https://github.com/kegedy/EMBSYS100/tree/dev/assignment06/control_user_led) <br>

3. Generate the map file for your program and provide details on:<br>

- a. How much total ROM your program is occupying?<br>
296 bytes

- b. How much total RAM your program is using?<br>
8192 bytes

- c. What part of your program is using the most ROM?<br>
rt7M_tl.a contains the largest proportion of the ROM which includes the vector_table object file.

- d. What part of your program is using the most RAM?<br>
The RAM is entirely composed of the Linker.
