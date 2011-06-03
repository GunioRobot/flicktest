#include "../include/ll.h"

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

  /* copy the element */
  memcpy(temp->element, &ele, esize);

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

int LLdeletei(LLmeta *lm, LL *ele)
{
  if (ele == NULL|| lm == NULL)
  {
    return 1;
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
  if (root !=NULL )
  {
    printf("t %d ", *(int*)root->element);
    return LLtraverse(root->next);
  }
  else
  {
    printf("\n");
    return 0;
  }
}


LL* LLfind(LL *root,  void *value, 
           int (* comparator) (const void *, const void *))
{
  if (root !=NULL)
  {
    //printf("%d %p    ", root->value, root);
    if (comparator(root->element, value) == 0)
    {
      return root;
    }
    else
      return LLfind(root->next, value, comparator);
  }
  else
    return NULL;
}

int LLdelete(LLmeta *lm, void *value, 
           int (* comparator) (const void *, const void *))
{
  LL *del = NULL;

  del = LLfind(lm->head, value, comparator);

  if (del != NULL)
  {
    return LLdeletei(lm, del);
  }
  else
    return 1;
}

