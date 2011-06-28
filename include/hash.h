#include <stdio.h>
#include <malloc.h>
#include "ll.h"
#define HT_SIZE 1023

typedef struct HT
{
  LLmeta  *lm[HT_SIZE];
  int      count;
  int    (*cmp)(void*, void*); /* compare function pointer  */
  int    (*dis)(void*);        /* display function pointer. */
}HT;

HT* hashInit();

unsigned int hashgen(void *value, size_t vsize);

int hashInsert(HT *htmeta, void *value, size_t vsize);

int hashFind(HT *ht, void *value, unsigned int vsize);
