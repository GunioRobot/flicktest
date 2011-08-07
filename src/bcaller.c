#include "../include/bsearch.h"

int main()
{
  int a [100];
  int i = 0;

  for (i = 0; i < 100; i++)
  {
    a[i] = i;
  }

  bsearch(a, sizeof(a)/sizeof(int), 22);
  return 0;
}
