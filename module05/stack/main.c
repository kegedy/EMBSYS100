#include<assert.h>
#include"stack.h"

int main()
{
    int result1, result2, testInt, a, b, c, d, e, f;
    
    // *******************************************************************
    // Test1: Retrieve item from an empty stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    testInt = 100;
    stack_init();
    
    // Act:
    result1 = stack_pop(&testInt);
      
    // Assert:
    assert(-1 == result1);
    assert(100 == testInt);
    
    
    // *******************************************************************
    // Test2: Successfully retrieve an item from the stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    result2 = 42;
    testInt = 100;
    stack_init();
    
    // Act:
    result1 = stack_push(1);
    result2 = stack_pop(&testInt);
    
    // Assert:
    assert(0 == result1);
    assert(0 == result2);
    assert(1 == testInt);
    
    
    // *******************************************************************
    // Test3: Fill stack, then get all items.
    // *******************************************************************
    // Arrange:
    testInt = 100;
    a=10,b=20,c=30;
    stack_init();
    
    // Act:
    stack_push(a);
    stack_push(b);
    stack_push(c);                                    
    
    // Assert:
    assert(0 == stack_pop(&testInt));
    assert(c == testInt);

    assert(0 == stack_pop(&testInt));
    assert(b == testInt);

    assert(0 == stack_pop(&testInt));
    assert(a == testInt);

    
    // *******************************************************************
    // Test4: Fill stack, then put one more item, should fail
    // *******************************************************************
    // Arrange:
    testInt = 100;
    a=10,b=20,c=30,d=40;
    stack_init();
    
    // Act:
    stack_push(a);
    stack_push(b);
    stack_push(c);
    
    // Assert:
    assert(-1 == stack_push(d));

    assert(0 == stack_pop(&testInt));
    assert(c == testInt);

    assert(0 == stack_pop(&testInt));
    assert(b == testInt);

    assert(0 == stack_pop(&testInt));
    assert(a == testInt);



    // ***********************************************************************
    // Test5: Fill stack, retrieve one item, then add item, then retieve all
    // ***********************************************************************
    // Arrange:
    testInt = 100;
    a=10,b=20,c=30,d=40;
    stack_init();
    
    // Act:
    stack_push(a);
    stack_push(b);
    stack_push(c);
    
    // Assert:
    assert(0 == stack_pop(&testInt));
    assert(c == testInt);

    assert(0 == stack_push(d));

    assert(0 == stack_pop(&testInt));
    assert(d == testInt);

    assert(0 == stack_pop(&testInt));
    assert(b == testInt);

    assert(0 == stack_pop(&testInt));
    assert(a == testInt);

    // ***********************************************************************
    // Test6: Fill stack and retrieve all items twice
    // ***********************************************************************
    // Arrange:
    testInt = 100;
    a=10,b=20,c=30,d=40,e=50,f=60;
    stack_init();
    
    // Act:
    stack_push(a);
    stack_push(b);
    stack_push(c);
    
    // Assert:
    assert(0 == stack_pop(&testInt));
    assert(c == testInt);

    assert(0 == stack_pop(&testInt));
    assert(b == testInt);

    assert(0 == stack_pop(&testInt));
    assert(a == testInt);

    assert(0 == stack_push(d));
    assert(0 == stack_push(e));
    assert(0 == stack_push(f));
    
    assert(-1 == stack_push(100));

    assert(0 == stack_pop(&testInt));
    assert(f == testInt);
   
    assert(0 == stack_pop(&testInt));
    assert(e == testInt);

    assert(0 == stack_pop(&testInt));
    assert(d == testInt);

    return 0;
}
