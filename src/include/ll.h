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

int LLinit(LLmeta**);

LL* LLappend(LLmeta *, void *, unsigned int );

int LLdelete(LLmeta *, void*, int (* comparator) (const void *, const void *));

int LLtraverse(LL *);

LL* LLfind(LL *,  void *, 
           int (* comparator) (const void *, const void *));

