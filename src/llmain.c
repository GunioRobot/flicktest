#include "ll.h"

int main()
{
  int i = 0;
  LL *root = NULL;
  LLmeta *lm = NULL;
  LLinit(&lm);

  for(i = 1; i < 100; i++)
  {
    LLappend(lm,(void*) i, sizeof(i));
    //LLinsert(&root, i);
  }
  LLtraverse(lm->head);

  return 0;
}

