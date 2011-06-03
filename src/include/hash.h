#include <stdio.h>
#include <malloc.h>
#define HT_SIZE 1023


typedef struct HT
{
  LLmeta *lm;
  unsigned int count;
  //unsigned int nele[HT_SIZE];
  LL* ele[HT_SIZE];
}HT;

HT* hashInit(LLmeta *lm);

int hashgen(void *value);

int hashInsert(HT *htmeta, void *value);

