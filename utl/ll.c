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

int LLdeletei(LLmeta *lm, LL *node)
{
  if (node == NULL|| lm == NULL)
  {
    return LL_FAIL;
  }
  if (lm->head == node)
  {
    lm->head       = node->next;
    lm->head->prev = NULL;
  }
  else if (lm->tail == node)
  {
    lm->tail       = node->prev;
    lm->tail->next = NULL;
  }
  else
  {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  /* dnodete nodement now */
  free(node->element);
  free(node);
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
    lm->count--;
    return LLdeletei(lm, del);
  }
  else
    return LL_FAIL;
}

int LLstat(LLmeta *lm, unsigned int *count)
{
  if (lm != NULL)
  {
    *count = lm->count;
    return LL_SUCC;
  }
  return LL_FAIL;
}

int LLeledestroy(LL **node)
{
  if (node == NULL || *node == NULL)
    return LL_SUCC;
  else if((*node)->next == NULL)
  {
    free((*node)->element);
    free(*node);
    *node = NULL;
    return LL_SUCC;
  }
  else
  {
    LLeledestroy(&(*node)->next);
    free((*node)->element);
    free(*node);
    *node = NULL;
  }
  return LL_SUCC;
}

int LLdestroy(LLmeta **lm)
{
  if (*lm == NULL)
    return LL_SUCC;
  else
  {
    LLeledestroy(&((*lm)->head));
    free(*lm);
    *lm = NULL;
    return LL_SUCC;
  }
}

int LLupdate(LLmeta *lm, void *newval, unsigned int vsize)
{
  int i = 0;
  LL *root = NULL;

  root = lm->head;
  while (lm != NULL && root !=NULL)
  {
    i = (*lm->cmpptr)(root->element, newval); 
    if (i == 0)
    {
      memcpy(root->element, newval, vsize);
      return LL_SUCC;
    }
    else
      root = root->next; 
  }
  return LL_FAIL;
}
int swap(LL **root)
{
  LL *one = NULL, *two = NULL;

  if (root == NULL || *root == NULL || (*root)->next == NULL)
    return LL_SUCC;

  one = *root;
  two = (*root)->next;
  one->next = two->next;
  two->next = one;
  *root = two;
  swap(&(one->next));
  return LL_SUCC;
}
int LLswaptwo(LLmeta *lm)
{
  swap(&(lm->head));
  return LL_SUCC;
}
