#include <stdio.h>
int main()
{
  int a = 127, i = 0;

  while(a)
  {
    a = a & a-1;
    i++;
  }
  printf("number of set bits %u\n", i);

  return 0;
}
