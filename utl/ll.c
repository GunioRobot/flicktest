#include "../include/ll.h"

int LLinit(LLmeta **lm, void *cmpptr, void *disptr)
{
  LLmeta *temp = NULL;

  temp = (LLmeta*)malloc(sizeof(LLmeta));
  if(temp == NULL)
  {
    printf("cant malloc1\n");
    return LL_FAIL;
  }
  temp->head   = NULL;
  temp->tail   = NULL;
  temp->cmpptr = cmpptr;
  temp->disptr = disptr;
  temp->count = 0;
  *lm          = temp;

  return LL_SUCC;
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
  temp->element = (void*)malloc(esize);
  if(temp->element == NULL)
  {
    printf("cant malloc1\n");
    return NULL;
  }

  /* copy the element */
  memcpy(temp->element, ele, esize);

  lm->count++;
  if(lm->head == NULL)
  {
    /* I am first record, set head and tail to me */
    lm->head = temp;
    lm->tail = temp;
    /* set prev and next to itself in case of first record */
    temp->prev = NULL;
    temp->next = NULL;
  }
  else
  {
    /* append in last, set prev pointer and make new element as tail */
    lm->tail->next = temp;
    temp->prev     = lm->tail;
    temp->next     = NULL;
    lm->tail       = temp;
  }
  return temp;
}

int LLdeletei(LLmeta *lm, LL *ele)
{
  if (ele == NULL|| lm == NULL)
  {
    return LL_FAIL;
  }
  if (lm->head == ele)
  {
    lm->head       = ele->next;
    lm->head->prev = NULL;
  }
  else if (lm->tail == ele)
  {
    lm->tail       = ele->prev;
    lm->tail->next = NULL;
  }
  else
  {
    ele->prev->next = ele->next;
    ele->next->prev = ele->prev;
  }

  /* delete element now */
  free(ele);
  return LL_SUCC;
}


int LLtraverse(LLmeta *lm)
{
  LL *root = NULL;

  if (lm == NULL || lm->head == NULL)
  {
    printf("\n");
    return LL_FAIL;
  }

  root = lm->head;
  while (root !=NULL )
  {
    lm->disptr(root->element);
    //printf("t %d ", *(int*)root->element);
    root = root->next;
  }
  printf("\n");
  return LL_SUCC;
}


LL* LLfind(LLmeta *lm, void *value)
{
  int i = 0;
  LL *root = NULL;

  root = lm->head;
  while (lm != NULL && root !=NULL)
  {
    i = (*lm->cmpptr)(root->element, value); 
    if (i == 0)
    {
      return root;
    }
    else
      root = root->next; 
  }

  return NULL;
}

int LLdelete(LLmeta *lm, void *value)
{
  LL *del = NULL;

  del = LLfind(lm, value); 

  if (del != NULL)
  {
    return LLdeletei(lm, del);
  }
  else
    return LL_FAIL;
}

