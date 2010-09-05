#include <stdio.h>
#include <malloc.h>
#define HT_SIZE 64

typedef struct HT
{
  LLmeta *lm;
  unsigned int count;
  //unsigned int nele[HT_SIZE];
  LL* ele[HT_SIZE];
}HT;

HT* hashInit(LLmeta *lm)
{
  int i = 0;
  HT *temp = NULL;

  temp = (HT*)malloc(sizeof(HT));
  if(temp == NULL)
  {
    printf("cant malloc1\n");
    return NULL;
  }
  
  temp->count = 0;
  temp->lm = lm;
  
  for(i = 0; i < HT_SIZE; i++)
  {
    //temp->nele[i] = 0;
    temp->ele[i] = NULL;
  }
  return temp;
}

int hashgen(void *value)
{
  int key = 0;

  /* lets have basic hash, take ASCI value as key */
  key = *(char*)value - 'a';
  return key;
}

int hashInsert(HT *htmeta, void *value)
{
  int key = hashgen(value);
  printf("value %c and key %d\n", *(char *)value, key);
  printf("htmeta %p count htmeta %d\n", htmeta, htmeta->count);

  htmeta->count++;
  LLdelete(htmeta->lm, htmeta->ele[key]);
  htmeta->ele[key] = LLappend(htmeta->lm, value, sizeof(char));    

  return 0;
}

