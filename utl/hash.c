#include "../include/hash.h"

#define HT_SUCC 0
#define HT_FAIL 1

HT* hashInit(HT **hm, void *cmpfptr, void *disfptr)
{
  int i = 0;
  HT *temp = NULL;

  temp = (HT*)malloc(sizeof(HT));
  if(temp == NULL)
  {
    printf("cant malloc1\n");
    return NULL;
  }

  for(i = 0; i < HT_SIZE; i++)
  {
    if(LLinit(&(temp->lm[i]), cmpfptr, disfptr) != 0)
    {
      printf("cant malloc1\n");
      return NULL;
    }
  }
  temp->cmp = cmpfptr;
  temp->dis = disfptr;
  temp->count = 0;
  *hm = temp;

  return temp;
}

unsigned int hashgen(void *value, size_t vsize)
{
  unsigned int key = 0;
  char *temp = value;

  while(vsize--)
  {
    key += *temp;
    temp++;
  }

  key = key % HT_SIZE;
  return key;
}

int hashInsert(HT *ht, void *value, size_t vsize)
{
  if (hashFind(ht, value, vsize) > 0)
  {
    unsigned int key = hashgen(value, vsize);
    LLappend(ht->lm[key], value, vsize);
    ht->count++;
    return 0;
  }
  else
    return 1;
}

int hashFind(HT *ht, void *value, unsigned int vsize)
{
  unsigned int key = hashgen(value, vsize);
  if(LLfind(ht->lm[key], value) != NULL)
  {
    printf("value found ");
    ht->dis(value);
    printf("\n");
    return 0;
  }
  else
    return 1;
}
