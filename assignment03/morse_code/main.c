#include <string.h>

#define RCC_BASE 0x40023800
#define RCC_AHB1ENR (*((unsigned int*)(RCC_BASE + 0x30)))

#define GPIOA_BASE 0x40020000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define GPIOA (1<<5)

void ld2_on(int s) {
// turns ld2 ON for s cycles. default state is off.
  volatile int counter = 0;
  GPIOA_ODR |= GPIOA;
  while(counter<s) {
    counter++;
  }
  GPIOA_ODR &= ~GPIOA;
  return;
}

void ld2_off(int s) {
// turns ld2 OFF for s cycles. default state is off.
  volatile int counter = 0;
  GPIOA_ODR &= ~GPIOA;
  while(counter<s) {
    counter++;
  }
  return;
}

void dot() {
// morse code short duration
  ld2_on(500000);ld2_off(500000);
  return;
}

void dash() {
// morse code long duration
  ld2_on(1500000);ld2_off(500000);
  return;
}

void morse_code(char c) {
// Transmits morse_code encoding via ld2
    switch(c) {
      case 'a':
        dot();dash();break;
      case 'b':
        dash();dot();dot();dot();break;
      case 'c':
        dash();dot();dash();dot();break;
      case 'd':
        dash();dot();dot();break;
      case 'e':
        dot();break;
      case 'f':
        dot();dot();dash();dot();break;
      case 'g':
        dash();dash();dot();break;
      case 'h':
        dot();dot();dot();dot();break;
      case 'i':
        dot();dot();break;
      case 'j':
        dot();dash();dash();dash();break;
      case 'k':
        dash();dot();dash();break;
      case 'l':
        dot();dash();dot();dot();break;
      case 'm':
        dash();dash();break;
      case 'n':
        dash();dot();break;
      case 'o':
        dash();dash();dash();break;
      case 'p':
        dot();dash();dash();dot();break;
      case 'q':
        dash();dash();dot();dash();break;
      case 'r':
        dot();dash();dot();break;
      case 's':
        dot();dot();dot();break;
      case 't':
        dash();break;
      case 'u':
        dot();dot();dash();break;
      case 'v':
        dot();dot();dot();dash();break;
      case 'w':
        dot();dash();dash();break;
      case 'x':
        dash();dot();dot();dash();break;
      case 'y':
        dash();dot();dash();dash();break;
      case 'z':
        dash();dash();dot();dot();break;
      default:
        break;
    }  
}

int main()
{
  // Enable clock to Peripheral
  RCC_AHB1ENR |= 0x1;
  
  // Set GPIO5 to Output
  GPIOA_MODER |= 0x400;
  
  while(1) {
    char name[5] = "kevin";
    for (int i=0;i<strlen(name);i++) {
      morse_code(name[i]);
      ld2_off(1500000);
    }
    ld2_off(10000000);
  }
  return 0;
}
