//#define RCC_BASE 0x40023800
//#define RCC_AHB1ENR (*((unsigned int*)(RCC_BASE + 0x30)))

//#define GPIOA_BASE 0x40020000
//#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
//#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

//#define GPIOA (1<<5)

void main(void)
{
  // 1. Enable clock to Peripheral
  // RCC_AHB1ENR Address 0x40023830 // Write: 0x1
  // bit_band_base + (byte_offset x 32) + (bit_number * 4)
  *((unsigned int*)((0x42000000) + (0x23830 * 32) + (0 * 4))) = 0x1;
  
  // 2. Set GPIO5 to Output
  // GPIOA_MODER5 Address 0x40020100 // Write: 0x400
  // bit_band_base + (byte_offset x 32) + (bit_number * 4)
  // *((unsigned int*)((0x42000000) + (0x20000 * 32) + (10 * 4))) = 0x1;
  *((unsigned int*)((0x42000000) + (0x20001 * 32) + (2 * 4))) = 0x1;

  // 3. Write 1 or 0 to turn ON/OFF LED
  // GPIOA_ODR5 Address 0x40020014 // Write: 0x20
  // bit_band_base + (byte_offset x 32) + (bit_number * 4)
  // *((unsigned int*)((0x42000000) + (0x20014 * 32) + (5 * 4))) = 0x1;
  volatile int counter;
  while(1)
  {
    counter=0;
    while (counter < 1000000)
    {
      counter++;
    }
    *((unsigned int*)((0x42000000) + (0x20014 * 32) + (5 * 4))) = 0x1;
    counter=0;
    while (counter < 1000000)
    {
      counter++;
    }
    *((unsigned int*)((0x42000000) + (0x20014 * 32) + (5 * 4))) = 0x0;
  }
  
}
