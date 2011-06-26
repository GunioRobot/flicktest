#include "../include/heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minheap_compare(minheap *hp, void *i, void *j)
{
  return (*(hp->cmp))(i, j);
}

int minheap_verify(minheap *hp)
{
  int i = 0;

  for (i = hp->len; i > 1; i--)
  {
    if (minheap_compare(hp, hp->data[i], hp->data[i/2]) < 0)
    {
      (*hp->dis)(hp->data[i]);
      minheap_traverse(hp);
      exit(1);
      return MINHEAP_FAIL;
    }
  }
  return MINHEAP_SUCC;
}

void minheap_swap(void **data1, void **data2)
{
  void *temp;

  temp   = *data1;
  *data1 = *data2;
  *data2 = temp;
  return;
}

int minheap_heapify(minheap *hp, unsigned int ele)
{
  unsigned parent = ele/2;
  
  if (parent == 0)
    return MINHEAP_SUCC;

  if (minheap_compare(hp, hp->data[parent], hp->data[ele]) > 0)
  {
    minheap_swap(&hp->data[parent], &hp->data[ele]);
    minheap_heapify(hp, parent);
  }
  return MINHEAP_SUCC;
}


int minheap_init(minheap **heap, unsigned int max_len, void *cmp, void *dis)
{
  int      i  = 0;
  minheap *hp = NULL;

  if (max_len > HEAPMAXLEN)
    return MINHEAP_BARGS;

  hp = (minheap*)malloc(sizeof(minheap));
  if (hp == NULL)
  {
    return MINHEAP_FAIL;
  }
  hp->len     = 0;
  hp->max_len = max_len;
  hp->cmp     = cmp;
  hp->dis     = dis;

  for (i = 0; i < HEAPMAXLEN; i++)
  {
    hp->data[i] = NULL;
  }
  *heap = hp;
  return MINHEAP_SUCC;
}

int minheap_add(minheap *hp, void *data, unsigned int size)
{
  void *temp = NULL;

  if (hp->len == hp->max_len)
    return MINHEAP_FULL;

  temp = malloc(size);
  memcpy(temp, data, size);  
  hp->len++;
  hp->data[hp->len] = temp;

  /*printf("data added ");
  (*hp->dis)(hp->data[hp->len]);
  printf("\n");*/

  minheap_heapify(hp, hp->len);

  return minheap_verify(hp);
}


int minheap_traverse(minheap *hp)
{
  int i = 0;

  for (i = 1; i < hp->len+1; i++)
  {
    printf("%u: ", i);
    (*hp->dis)(hp->data[i]);
    printf("|");
  }
  printf("\n");
  return MINHEAP_SUCC;
}

int minheap_findmin(minheap *hp, void **ele)
{
  if (hp->len == 0)
  {
    *ele = NULL;
    return MINHEAP_SUCC;
  }

  *ele = hp->data[1];
  return MINHEAP_SUCC;
}


int minheap_rheapify(minheap *hp, unsigned int ele)
{
  unsigned int rchild = ele *2 +1, lchild = ele *2;
  int          cmp    = 0;

  if (lchild <= hp->len && rchild <= hp->len)
  {
    cmp = minheap_compare(hp, hp->data[lchild], hp->data[rchild]); 
    if (cmp > 0)
    {
      if (minheap_compare(hp, hp->data[ele], hp->data[rchild]) > 0)
      {
        minheap_swap(&hp->data[rchild], &hp->data[ele]);
        return minheap_rheapify(hp, rchild);
      }
    }
    else 
    {
      if (minheap_compare(hp, hp->data[ele], hp->data[lchild]) > 0)
      {
        minheap_swap(&hp->data[lchild], &hp->data[ele]);
        return minheap_rheapify(hp, lchild);
      }
    }
  }
  else if (lchild <= hp->len)
  {
    if (minheap_compare(hp, hp->data[ele], hp->data[lchild]) > 0)
    {
      minheap_swap(&hp->data[lchild], &hp->data[ele]);
      return minheap_rheapify(hp, lchild);
    }
  }

  return MINHEAP_SUCC;
}

int minheap_rmroot(minheap *hp, void *ele, unsigned int esize)
{
  if (hp->len == 0)
  {
    return MINHEAP_FAIL;
  }
  memcpy(ele, hp->data[1], esize);
  free(hp->data[1]);
  hp->data[1]       = hp->data[hp->len];
  hp->data[hp->len] = NULL;
  hp->len--;

  minheap_rheapify(hp, 1);
  return minheap_verify(hp);
}
