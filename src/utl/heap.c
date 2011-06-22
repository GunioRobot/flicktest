#include "../include/heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minheap_init(minheap **heap, unsigned int max_len, void *cmp, void *dis)
{
  int i = 0;
  minheap *hp = NULL;

  if (max_len > HEAPMAXLEN)
    return MINHEAP_BARGS;

  hp = (minheap*)malloc(sizeof(minheap));
  if (hp == NULL)
  {
    return MINHEAP_FAIL;
  }
  hp->len = 0;
  hp->max_len = max_len;
  hp->cmp = cmp;
  hp->dis= dis;

  for (i = 0; i < HEAPMAXLEN; i++)
  {
    hp->data[i] = NULL;
  }
  *heap = hp;
  return MINHEAP_SUCC;
}

int minheap_add(minheap *hp, void *data, unsigned int size)
{
  if (hp->len == hp->max_len)
    return MINHEAP_FULL;

  void *temp = NULL;

  temp = (void*)malloc(sizeof(size));
  memcpy(temp, data, size);  
  hp->data[(hp->len)+1] = temp;
  hp->len++;
  printf("data added %d\n", *(int*)data);
  return MINHEAP_SUCC;
}

void minheap_swap(void *data1, void *data2)
{
  void *temp;

  temp = data1;
  data1 = data2;
  data2 = temp;
  return;
}
int minheap_compare(minheap *hp, void *i, void *j)
{
  return (*hp->cmp)(&i, &j);
}

int minheap_heapify(minheap *hp, unsigned int ele)
{
  unsigned parent = ele/2;
  
  if (parent == 0)
    return MINHEAP_SUCC;

  if (minheap_compare(hp, hp->data[parent], hp->data[ele]) > 0)
  {
    printf("heapified\n");
    minheap_swap(hp->data[parent], hp->data[ele]);
    minheap_heapify(hp, parent);
  }
  return MINHEAP_SUCC;
}

int minheap_traverse(minheap *hp)
{
  int i = 0;

  for (i = 1; i < hp->len+1; i++)
  {
    printf("%u: ", i);
    (*hp->dis)(hp->data[i]);
  }
  return MINHEAP_SUCC;
}
