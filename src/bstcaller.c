#include "../include/bst.h"
#include <stdio.h>
#include <stdlib.h>

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
  int i = 0;
  bst_meta *bm = NULL;

  BSTinit(&bm, cmpele, disele);

  for (i = 0; i < 10; i++)
  {
    BSTadd(bm, &i, sizeof(i));
  }

  for (i = 0; i < 10; i+=2)
  {
    if (BSTfind(bm, &i) == BST_SUCC)
      printf("element found %d\n", i);
  }
  BSTdestroy(&bm);
  return 0;
}
