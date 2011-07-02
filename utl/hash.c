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

unsigned int hashgen(unsigned char *value, size_t vsize)
{
  unsigned int key = 0;
  unsigned int i = 0;

  for (i = 0; i < vsize; ++i)
  {
    key += value[i];
    key += (key << 10);
    key ^= (key >> 6);
  }
  key += (key << 3);
  key ^= (key >> 11);
  key += (key << 15);
  return (key & (HT_SIZE - 1));
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
    return 0;
  }
  else
    return 1;
}

int HashAnalyse(HT *ht, float *sdev)
{
  unsigned int i = 0, count = 0;
  float std_dev = 0, avg = 0;

  avg = ht->count/HT_SIZE;
  
  for (i = 0; i < HT_SIZE; i++)
  {
    LLstat(ht->lm[i], &count);

    if (count > avg)
      std_dev += (count - avg);
    else
      std_dev += (avg - count);
  }
  *sdev = (std_dev/HT_SIZE)/avg;
  return HT_SUCC;
}
