#include <stdio.h>
#include <malloc.h>
#include <string.h>
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

/*
int LLinit(LLmeta **lm);

LL* LLappend(LLmeta *lm, void *ele, unsigned int esize);

int LLdelete(LLmeta *lm, LL *ele);

int LLtraverse(LL *root)

int LLfind(LL *root,  void * value, 
           int (* comparator) (const void *, const void *))

           */
