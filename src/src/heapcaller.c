#include "../include/heap.h"
#include <stdio.h>

int display(void *data1)
{
  printf("%d\n", *(int*)data1);
  return MINHEAP_SUCC;
}

int compare(void *data1, void *data2)
{
  if (*(int*)data1 == *(int*)data2)
    return 0;
  else if(*(int*)data1 > *(int*)data2)
    return 1;
  else
    return -1;
}

int main()
{
  int i = 0;
  minheap *hp = NULL;

  minheap_init(&hp, 50, compare, display);
  for (i = 1; i < 20; i++)
  {
    minheap_add(hp, &i, sizeof(i));
  }
  minheap_traverse(hp);
  return 0;
}


