#include "stm32f401xe.h"
#define SYS_CLOCK_HZ 16000000u
#include <stdio.h>

void blink(void);
void set_SysTick(uint32_t load);
void delay(uint32_t delayInMilliseconds);

void blink(void){
    GPIOA->ODR ^= GPIO_ODR_OD5;
}
void set_SysTick(uint32_t load){
    SysTick->LOAD = load - 1;
    SysTick->VAL = 0x0;
    // Bit0: Enables the counter.
    // Bit1: SysTick exception request enable
    // Bit2: Clock source selection
    // Bits 0,1,2 are all on. 
    SysTick->CTRL = 0x7;    
}
void delay(uint32_t delayInMilliseconds){
    int ratio = SYS_CLOCK_HZ/1000; // cycles per ms
    int cycles = ratio * delayInMilliseconds; //total cycles
    // http://www.ti.com/lit/ml/swrp171/swrp171.pdf
    while(cycles>0) {
        if (cycles<SYS_CLOCK_HZ){
            set_SysTick(cycles);
            // CTRL_COUNTFLAG
            while((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)== 0);
            cycles -= cycles;
        } else{
            set_SysTick(SYS_CLOCK_HZ);
            // CTRL_COUNTFLAG
            while((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)== 0);
            cycles -= SYS_CLOCK_HZ;
        }
    }
}

void main(void)
{
    // *((unsigned int*)(0x40023800+0x30)) |= 0x1;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // *((unsigned int*)(0x40020000+0x00)) |= 0x400;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    
    while(1){
        delay(2000);
        //delay(20);
        //delay(1);
        //delay(1000);
        blink();
    }
}
