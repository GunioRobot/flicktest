#include "../include/hash.h"
#include "../include/ll.h"

HT* hashInit(HT **hm, void *cmpfptr, void *disfptr)
{
  int i = 0;
  HT *temp = NULL;
  LLmeta **lm = NULL;

  temp = (HT*)malloc(sizeof(HT));
  if(temp == NULL)
  {
    printf("cant malloc1\n");
    return NULL;
  }

  for(i = 0; i < HT_SIZE; i++)
  {
    if(LLinit(&lm[i], fptr) != 0)
    {
      printf("cant malloc1\n");
      return NULL;
    }
  }
  temp->cmp = cmpfptr;
  temp->dis = disfptr;
  temp->count = 0;

  return temp;
}

int hashgen(void *value, size_t vsize)
{
  int key = 0;

  /* lets have basic hash, take ASCI value as key */
  key = *(char*)value - 'a';
  return key;
}

int hashInsert(HT *htmeta, void *value, size_t vsize)
{
  int key = hashgen(value, vsize);

  return 0;
}

