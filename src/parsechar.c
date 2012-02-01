#include "../include/ll.h"
#include "../include/hash.h"

int main()
{
  char *c;
  //int i = 0;
  char *str = "gabchcfgajbdghfjiyfg";
  //char *chstr = "ghj";
  //LL *root = NULL;
  LLmeta *lm = NULL;
  HT *ht = NULL;
  LLinit(&lm);
  ht = hashInit(lm);



  for(c = str ; *c != '\0'; c++)
  {
    hashInsert(ht, (void*)c);
    //if (ht->count = 3)
  }

/*
  for (i = 0; i < 4; i++)
  {
    LLappend(lm, (void*)&i, sizeof(i));
  }

  LLtraverse(lm->head);
  */
  return 0;
}

