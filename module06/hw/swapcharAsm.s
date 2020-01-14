/*******************************************************************************
File name       : swapcharAsm.s
Description     : Assembly language function for square
*******************************************************************************/   

    EXTERN PrintString  // PrintString is defined outside this file.
    EXTERN myCstr       // myCstr defined outside this file.
    
    PUBLIC swapcharAsm       // Exports symbols to other modules
                        // Making swapcharAsm available to other modules.
    
// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : swapcharAsm
Description     : Calls C code to print a string; 
                  computes the square of its input argument
C Prototype     : void swapcharAsm(char* x, char* y)
                : Where val is the value to calculate it's square
Parameters      : R0: Address of val
Return value    : R0
*******************************************************************************/  
/* 
void swap_char (char* x, char* y){
	char tmp = *x;
	*x = *y;
	*y = tmp;
}
char x = 'a';
char y = 'b';
swap_char(&x,&y);
*/

swapcharAsm
    LDRB R2, [R0] // R2 = x; value at R0 is loaded into R2
    LDRB R3, [R1] // R3 = y; value at R1 is loaded into R3
    STRB R3, [R0] // store value at R3 into address R0 
    STRB R2, [R1] // store value at R2 into address R1 
    BX LR         // return (with function result in R0)

    END
