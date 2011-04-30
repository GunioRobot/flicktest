#include <stdio.h>
#include <malloc.h>
typedef struct LLmeta
{
  unsigned int count;
  struct LL    *head;
  struct LL    *tail;
}LLmeta;

typedef struct LL
{
  //int value;
  void *element;
  struct LL *next;
  struct LL *prev;
  //struct LL *right;
}LL;

int LLinit(LLmeta **lm)
{
  LLmeta *temp = NULL;

  temp = (LLmeta*)malloc(sizeof(LLmeta));
  if(temp == NULL)
  {
    printf("cant malloc1\n");
    return -1;
  }
  temp->head = NULL;
  temp->tail = NULL;
  *lm = temp;


  return 0;
}

LL* LLappend(LLmeta *lm, void *ele, unsigned int esize)
{
  LL *temp = NULL;
  temp = (LL*)malloc(sizeof(LL));
  if(temp == NULL)
  {
    printf("cant malloc1\n");
    return NULL;
  }
  temp->element = (void*)malloc(sizeof(esize));
  if(temp->element == NULL)
  {
    printf("cant malloc1\n");
    return NULL;
  }

  *(int*)(temp->element) = *(int*)ele;
  lm->count++;
  if(lm->head == NULL)
  {
    /* I am first record, set head and tail to me */
    lm->head = temp;
    lm->tail = temp;
    /* set prev and next to itself in case of first record */
    temp->prev = temp;
    temp->next = temp;
  }
  else
  {
    /* append in last, set prev pointer and make new element as tail */
    lm->tail->next = temp;
    temp->prev = lm->tail;
    temp->next = NULL;
    lm->tail = temp;
  }
  return temp;
}

int LLdelete(LLmeta *lm, LL *ele)
{
  if (ele == NULL)
  {
    return 0;
  }
  if (lm->head == ele)
  {
    lm->head = ele->next;
    lm->head->prev = NULL;
  }
  else if (lm->tail == ele)
  {
    lm->tail = ele->prev;
    lm->tail->next = NULL;
  }
  else
  {
    ele->prev->next = ele->next;
    ele->next->prev = ele->prev;
  }
  /* delete element now */
  free(ele);
  return 1;
}

int LLtraverse(LL *root)
{
  if (root !=NULL)
  {
    //printf("%d %p    ", root->value, root);
    printf("%d   \n ", *(int*)root->element);
    return LLtraverse(root->next);
  }
  else
    return 0;
}

