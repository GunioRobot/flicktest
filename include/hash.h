#include <stdio.h>
#include <malloc.h>
#define HT_SIZE 1023


typedef struct HT
{
  LLmeta* lm[HT_SIZE];
  int count;
  int (*cmp)(void*, void*); /* compare function pointer */
  int (*dis)(void*); /* display function pointer. Not used much */

  //unsigned int nele[HT_SIZE];
}HT;

HT* hashInit();

int hashgen(void *value, size_t vsize);

int hashInsert(HT *htmeta, void *value, size_t vsize);

