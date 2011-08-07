#include "../include/bsearch.h"
#include <stdio.h>

int bsearch(int a[], int count, int find)
{
  int l = 0, u = count -1;

  int m = 0; 

  while(u>=l)
  {
    m = l + (u - l)/2;
    printf("u %d l %d m %d\n", u, l, m);
    if (a[m] == find)
    {
      printf("found %d\n", find);
      return 0;
    }
    else if(a[m] < find)
    {
      l = m + 1;
    }
    else
    {
      u = m - 1;
    }
  }
  return 1;
}

