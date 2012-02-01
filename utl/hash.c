#include "../include/hash.h"


HT* hashInit(HT **hm, void *cmpfptr, void *disfptr, unsigned int type)
{
  int i = 0;
  HT *temp = NULL;

  temp = (HT*)malloc(sizeof(HT));
  if(temp == NULL)
  {
    printf("cant malloc1\n");
    return NULL;
  }

  if (type == HT_LL)
  {
    for(i = 0; i < HT_SIZE; i++)
    {
      if(LLinit(&(temp->lm[i]), cmpfptr, disfptr) != 0)
      {
        printf("cant malloc1\n");
        return NULL;
      }
    }
    temp->type = type;
  }
  else if (type == HT_BST)
  {
   for(i = 0; i < HT_SIZE; i++)
    {
      if(BSTinit(&(temp->bm[i]), cmpfptr, disfptr) != BST_SUCC)
      {
        printf("cant malloc1\n");
        return NULL;
      }
    }
    temp->type = type;
  }

  temp->cmp = cmpfptr;
  temp->dis = disfptr;
  temp->count = 0;
  *hm = temp;

  return temp;
}

int hashDestroy(HT **hm)
{
  int i = 0;
  if ((*hm)->type == HT_LL)
  {
    for (i = 0; i < HT_SIZE; i++)
    {
      LLdestroy(&((*hm)->lm[i]));
    }
  }
  else if ((*hm)->type == HT_BST)
  {
    for (i = 0; i < HT_SIZE; i++)
    {
      BSTdestroy(&((*hm)->bm[i]));
    }
  }
  free(*hm);
  *hm = NULL;

  return HT_SUCC;
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
  unsigned int key = 0;
  if (hashFind(ht, value, vsize) > 0)
  {
    key = hashgen(value, vsize);

    if (ht->type == HT_LL)
      LLappend(ht->lm[key], value, vsize);
    else if (ht->type == HT_BST)
      BSTadd(ht->bm[key], value, vsize);

    ht->count++;
    return HT_SUCC;
  }
  else
    return HT_FAIL;
}

int hashFind(HT *ht, void *value, unsigned int vsize)
{
  unsigned int key = 0;
  key = hashgen(value, vsize);
  if (ht->type == HT_LL)
  {
    if(LLfind(ht->lm[key], value) != NULL)
    {
      return HT_SUCC;
    }
    else
      return HT_FAIL;
  }
  else if (ht->type == HT_BST)
  {
    if(BSTfind(ht->bm[key], value) == BST_SUCC)
    {
      return HT_SUCC;
    }
    else
      return HT_FAIL;
  }
  return HT_FAIL;
}

int HashAnalyse(HT *ht, float *sdev)
{
  unsigned int i = 0, count = 0;
  float std_dev = 0, avg = 0;

  avg = ht->count/HT_SIZE;

  if (ht->type == HT_LL)
  {
    for (i = 0; i < HT_SIZE; i++)
    {
      LLstat(ht->lm[i], &count);

      if (count > avg)
        std_dev += (count - avg);
      else
        std_dev += (avg - count);
    }
  }
  else if (ht->type == HT_BST)
  {
    for (i = 0; i < HT_SIZE; i++)
    {

      BSTstat(ht->bm[i], &count);

      if (count > avg)
        std_dev += (count - avg);
      else
        std_dev += (avg - count);
    }
  }

  *sdev = (std_dev/HT_SIZE)/avg;
  return HT_SUCC;
}

int hashupdate(HT *ht, void *value, unsigned int vsize)
{
  unsigned int key = 0;
  key = hashgen(value, vsize);
  if (ht->type == HT_LL)
  {
    if(LLfind(ht->lm[key], value) != NULL)
    {
      LLupdate(ht->lm[key], value, vsize);
      return HT_SUCC;
    }
    else
      return HT_FAIL;
  }
  else if (ht->type == HT_BST)
  {
    if(BSTfind(ht->bm[key], value) == BST_SUCC)
    {
      BSTupdate(ht->bm[key], value, vsize);
      return HT_SUCC;
    }
    else
      return HT_FAIL;
  }
  return HT_FAIL;
}



