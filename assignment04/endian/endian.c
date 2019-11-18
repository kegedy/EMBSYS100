#include <stdio.h>

void main(void)
{
  int myInt = 0x0001;
  char* pChar = (char*)&myInt;
  if (pChar[0]) printf("Little Endian");
  else printf("Big Endian");
 }
