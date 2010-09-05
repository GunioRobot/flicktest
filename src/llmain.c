#include "ll.h"
#include "hash.h"

int main()
{
  char c = 'a';
  int i = 0;
  LL *root = NULL;
  LLmeta *lm = NULL;
  HT *ht = NULL;
  LLinit(&lm);
  ht = hashInit(lm);

  /*
  for(c = 'a' ; c <= 'd'; c++)
  {
    //hashInsert(ht, (void*)&c);
    LLappend(lm, (void*)&c, sizeof(c));
  }
  LLtraverse(lm->head);
*/

  for (i = 0; i <4; i++)
  {
    LLappend(lm, (void*)&i, sizeof(i));
  }

  LLtraverse(lm->head);
  return 0;
}

