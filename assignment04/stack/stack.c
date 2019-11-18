#include "stack.h"
#define STACK_SIZE 3

// Backing store
int StackStore[STACK_SIZE];

// Pointers to queue elements for adding and retrieving
int* Ptr;

// Stack is Empty if putPtr==Ptr;
// Stack is Full if putPtr+1 > Address of last element in the queue;


void stack_init(void) {
    // Initialize internals of the queue
    for(int i=0; i<STACK_SIZE; i++){
        StackStore[i] = 0x80000000;
    }
    Ptr = &StackStore[0];
}

int stack_empty(void) {
    if (Ptr == &StackStore[0]){
        return 1;
    } else {
        return 0;
    }
}

int stack_full(void) {
    if (Ptr == &StackStore[STACK_SIZE]){
        return 1;
    } else {
        return 0;
    }
}

int stack_push(int data) {
    // Add data to stack
    // If stack is full return error
    // Otherwise return success
 
    if (stack_full()){
        // stack is full
        return -1;
    }  
    
    *Ptr = data;
    Ptr++;
    return 0;
}


int stack_pop(int* data) {  
    // Get data from stack
    // If stack is empty return error
    // Otherwise return success
    
    if (stack_empty()){
        return -1;
    }

    *data = *(--Ptr);
    
    return 0;
}
