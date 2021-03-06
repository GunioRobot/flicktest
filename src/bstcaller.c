#include "../include/bst.h"
#include <stdio.h>
#include <stdlib.h>
#define BST_STRLEN 5

/* display element */
int disele(const void *ele1)
{
  if (ele1 == NULL)
    return 1;
  printf("%d \n", *(int*)ele1);
    return 0;
}

/* compare element of integer type */
int cmpele(const void *ele1, const void *value)
{
  if (ele1 == NULL || value == NULL)
    return 1;
  else if (*(int*)ele1== *(int*)value)
  {
    return 0;
  }
  else
    return (*(int*)ele1 - *(int*)value);
}

/* Main caller for integer data */
int bstint()
{
  int i = 0, j = 0;
  bst_meta *bm = NULL;

  BSTinit(&bm, cmpele, disele);

  for (i = 0; i < 100; i++)
  {
    j = (rand () % 1234);
    BSTadd(bm, &j, sizeof(j));
  }

  for (i = 0; i < 10; i+=2)
  {
    if (BSTfind(bm, &i) == BST_SUCC)
      printf("element found %d\n", i);
  }
  BSTtraversal(bm);
  BSTdestroy(&bm);

  return 0;
}

/* Display string element */
int diselestr(const void *ele1)
{
  if (ele1 == NULL)
    return 1;
  printf("%s ", (char*)ele1);
    return 0;
}

/* compare strings */
int cmpelestr(const void *ele, const void *value)
{
  if (ele == NULL || value == NULL)
    return 1;
  else
    return strcmp((char*)ele, (char*)value);
}

/* Main caller for string data */
int bststr()
{
  int i = 0, j = 0;
  bst_meta *bm = NULL;
  char          k[BST_STRLEN];

  BSTinit(&bm, cmpelestr, diselestr);
  for (i = 0; i <3000; i++)
  {
    for (j = 0; j < BST_STRLEN-2; j++)
    {
      k[j] = 'a' + (rand () % 26);
    }
    k[j] = 0;
    if (BSTfind(bm, (void*)k) == BST_SUCC)
    {
      BSTupdate(bm, (void*)k, sizeof(k));
    }
    else
    {
      BSTadd(bm, &k, sizeof(k));
    }
  }

  BSTtraversal(bm);
  BSTdestroy(&bm);

  return 0;
}



int main()
{
  bstint();
  bststr();
  return 0;
}
