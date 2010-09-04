#include <stdio.h>
#include <malloc.h>
typedef struct LLmeta
{
  unsigned int count;
  struct LL *head;
  struct LL *tail;
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
int LLappend(LLmeta *lm, void *ele, unsigned int esize)
{
  LL *temp = NULL;
  temp = (LL*)malloc(sizeof(LL));
  if(temp == NULL)
  {
    printf("cant malloc1\n");
    return -1;
  }
  temp->element = (void*)malloc(sizeof(esize));
  if(temp->element == NULL)
  {
    printf("cant malloc1\n");
    return -1;
  }
  temp->element = ele;
  lm->count++;
  if(lm->head == NULL)
  {
    /* I am first record, set head and tail to me */
    lm->head = temp;
    lm->tail = temp;
    /* set prev and next to itself in case of first record */
    temp->prev = temp;
    temp->next = temp;
    printf("first ele added %d\n", (int)temp->element);
  }
  else
  {
    /* append in last, set prev pointer and make new element as tail */
    printf("head %d and tail %d\n", (int)lm->head->element, (int)lm->tail->element);
    temp->prev = lm->tail;
    lm->tail->prev->next = temp;
    temp->next = NULL;
    lm->tail = temp;
    printf("ele added %d\n", (int)temp->element);
    printf("prev %d\n", (int)temp->prev->element);

  }

  return 0;
}
int LLinsert(LL **root, int value)
{
  LL *temp = NULL;
  //LL *trav = NULL;
  if(*root == NULL)
  {
    temp = (LL*)malloc(sizeof(LL));
    if(temp == NULL)
    {
      printf("cant malloc1\n");
      return -1;
    }
    temp->element = (void*)malloc(sizeof(int));
    if(temp->element == NULL)
    {
      printf("cant malloc1\n");
      return -1;
    }

    temp->element = (int *)value;
    temp->next = NULL;
    *root = temp;
  }
  else
    return LLinsert(&(*root)->next, value);
  return 0;
}

int LLtraverse(LL *root)
{
  if (root !=NULL)
  {
    //printf("%d %p    ", root->value, root);
    printf("%d   \n ", (int )root->element);
    return LLtraverse(root->next);
  }
  else
    return 0;
}
/*  
int LLreverse(LL **root1)
{
  LL *root=*root1;
  LL *one = NULL, *two = NULL, *three = NULL;
  one = root;
  two = root->next;
  one->next = NULL;
  //printf("\n");
  while(two != NULL)
  {
    //printf ("one %p two %p three %p\n", one, two, three);
    three = two->next;
    two->next = one;
    //LLtraverse(two);
    //printf("\n");
    one = two;
    two = three;
  }
  //LLtraverse(one);
  root = one;
  printf ("one %p two %p three %p\n", one, two, three);
  *root1 = root;
  return 0;
}
*/
