#include <stdio.h>

unsigned int snoob(unsigned int a)
{
  unsigned int smallest, ripples, ones;
  //x = xxx011110000
  smallest = a & -a; //0000 0001 0000
  printf("smallest %u\n", smallest);
  ripples = a + smallest; // xxx1 0000 0000
  printf("ripples %u\n", ripples);
  ones = a ^ ripples; // 0001 1111 0000
  printf("ones %u\n", ones);
  ones = (ones >> 2)/smallest; // 0000 0000 0111
  printf("ones %u\n", ones);
  return ripples | ones;  //xxx1 0000 0111
}
main()
{
  int num;
  num = 3;
  printf(" %d Next higher number having same no." 
          "of 1's in it binary"
          "representation\n",snoob(num));
}
