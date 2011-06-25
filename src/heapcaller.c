#include "../include/heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MINHEAP_STRLEN 20 

int display(void *data1)
{
  printf("%d", *(int*)data1);
  return MINHEAP_SUCC;
}

int compare(void *data1, void *data2)
{
  int i = 0;

  i = *(int*)data1 - *(int*)data2;
  /* printf("compare called %d %d %d\n", *(int*)data1, *(int*)data2, i);*/

  return i;
}

int call_intheap()
{
  int i = 0, j = 0;
  minheap *hp = NULL;
  unsigned int iseed = (unsigned int)time(NULL);
  srand (iseed);

  minheap_init(&hp, 20, compare, display);
  for (i = 1; i < 19; i++)
  {
    j = rand () % 1000;
    minheap_add(hp, &j, sizeof(j));
  }
  printf("all data added\n");


  for (i = 0; i < 15; i++)
  {
    if (minheap_rmroot(hp, &j, sizeof(j)) == 0)
    {
      printf("\n %d root: %d \n",i, j);
    }
    else
      return 1;
  }
  return 0;

}
int str_display(void *data1)
{
  printf("%s", (char*)data1);
  return MINHEAP_SUCC;
}

int str_compare(void *data1, void *data2)
{
  return strcmp(data1, data2);
}

int call_strheap()
{
  int i = 0, j = 0;
  minheap *hp = NULL;
  char k[MINHEAP_STRLEN];
  unsigned int iseed = (unsigned int)time(NULL);
  srand (iseed);

  minheap_init(&hp, 500, str_compare, str_display);
  for (i = 1; i < 400; i++)
  {
    for (j = 0; j < MINHEAP_STRLEN-2; j++)
    {
      k[j] = 'a' + (rand () % 26);
    }
    k[j] = 0;
    minheap_add(hp, &k, sizeof(k));
  }

  for (i = 0; i < 399; i++)
  {
    minheap_rmroot(hp, &k, sizeof(k));
    printf("%d root: %s \n",i, k);
  }
  return 0;

}

int main()
{
  call_intheap();
  call_strheap();
  return 0;
}


