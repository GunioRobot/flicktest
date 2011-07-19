#include <stdio.h>
#include <stdlib.h>
#include "../include/hash.h"

int disele(const void *ele1)
{
  if (ele1 == NULL)
    return 1;
  printf("%d ", *(int*)ele1);
    return 0;
}


int cmpele(const void *ele1, const void *value)
{
  if (ele1 == NULL || value == NULL)
    return 1;
  else if (*(int*)ele1== *(int*)value)
  {
    return 0;
  }
  else
    return 1;
}


int main()
{
  int i = 0, j = 0, k = 0;
  HT *hm = NULL;
  float std_dev = 0.0;

  hashInit(&hm, cmpele, disele, HT_BST);

  for (i = 0; i < 100; i++)
  {
    j = (rand () % 100);
    k = 100 - j;
    if (hashFind(hm, &k, sizeof(k)) == HT_SUCC)
    {
      printf("complement found ");
      printf("i %d j %d k %d\n", i, j, k);
      exit(0);
    }

    if(hashInsert(hm, &j, sizeof(j)) > 0)
    {
      printf("%u:value already present:", i);
      printf("%d\n", j);
      i--;
    }
  }
  hashDestroy(&hm);
  return 0;

}
