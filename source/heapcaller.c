#include "../include/heap.h"
#include <stdio.h>
#include <stdlib.h>

int display(void *data1)
{
  printf("%d\n", *(int*)data1);
  return MINHEAP_SUCC;
}

int compare(void *data1, void *data2)
{
  int i = 0;

  i = *(int*)data1 - *(int*)data2;
  /* printf("compare called %d %d %d\n", *(int*)data1, *(int*)data2, i);*/

  return i;
}

int main()
{
  int i = 0, j = 0;
  minheap *hp = NULL;
  unsigned int iseed = (unsigned int)time(NULL);
  srand (iseed);

  minheap_init(&hp, 50, compare, display);
  for (i = 1; i < 40; i++)
  {
    j = rand () % 100;
    minheap_add(hp, &j, sizeof(j));
  }
  minheap_traverse(hp);
  return 0;
}


