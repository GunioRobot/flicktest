#include "../include/ll.h"

int cmpele(const void *ele1, const void *value)
{
  if (ele1 == NULL || value == NULL)
    return 1;
  else if (*(int*)ele1== *(int*)value)
  {
    return 0;
  }
  else
    return 1;
}

int main()
{
  LLmeta *lm = NULL;
  int i = 0;

  LLinit(&lm, cmpele);

  for (i = 0; i <30; i++)
    LLappend(lm, (void*)i, sizeof(i));


  for (i = 0; i <30; i+=2)
    LLdelete(lm, &i, cmpele);

  LLtraverse(lm->head);
  return 0;
}

