#include "stm32f401xe.h"
void delay(unsigned int iteration);

void delay(unsigned int iteration){
    while(iteration>0) iteration--;
}

void main(void)
{
    // *((unsigned int*)(0x40023800+0x30)) |= 0x1;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // *((unsigned int*)(0x40020000+0x00)) |= 0x400;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    while(1){
        delay(1000000);
        GPIOA->ODR |= GPIO_ODR_OD5; // ON
        delay(1000000);
        GPIOA->ODR &= ~GPIO_ODR_OD5; // OFF
    }
}
