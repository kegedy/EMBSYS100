int myIntArray[5] = {40, 41, 42, 43, 44};
char myCharArray[] = "Hello my array";
char *myString = "Hello my string";


int *myIntPtr = myIntArray;

int getIncorrectArraySize(char* p);

int main()
{
    // Poitner arithmetic
    int myInt = 0x77778888;
    int* pInt = &myInt;
    *pInt = 0x41424344;
    pInt++;     // What is the value of pInt?
    char* pChar = (char*)&myInt;
    *pChar = 0x00;  // Hint for Assignment 04
    pChar++;    // What is the value of pChar?

    // Pointer arithmetic with arrays
    *myIntPtr = 70;
    myIntPtr[1] = 2000;
    *(myIntPtr+1) = 72;
    *(myIntPtr+5) = 77;
    myIntPtr++;
    *myIntPtr = 100;
    

    // sizeof operator
    int numberOfCharElements = sizeof(myCharArray)/sizeof(myCharArray[0]);
    int numberOfElements = sizeof(myIntArray)/sizeof(myIntArray[0]);
    
    numberOfCharElements = getIncorrectArraySize(myCharArray);
    
    numberOfElements = sizeof(myIntPtr)/sizeof(myIntPtr[0]);
    
   
    (void)numberOfCharElements;
    (void)numberOfElements;      
    return 0;
}

int getIncorrectArraySize(char* p)
{
    return sizeof(p)/sizeof(p[0]);
}






