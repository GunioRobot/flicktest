#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define LL_SUCC 0
#define LL_FAIL 1


typedef struct LLmeta
{
  unsigned int   count;
  struct LL     *head;
  struct LL     *tail;
  int          (*cmpptr)  (const void *, const void *);
  int          (*disptr)  (const void *);
}LLmeta;

typedef struct LL
{
  void      *element;
  struct LL *next;
  struct LL *prev;
}LL;


int LLinit(LLmeta**, void *cmpfptr, void *disptr);

LL* LLappend(LLmeta *, void *, unsigned int);

int LLdelete(LLmeta *, void *);

int LLtraverse(LLmeta *);

LL* LLfind(LLmeta*, void *);

int LLupdate(LLmeta*, void *, unsigned int);

int LLstat(LLmeta *lm, unsigned int *count);

int LLeledestroy(LL **ele);

int LLdestroy(LLmeta **lm);

int LLswaptwo(LLmeta *lm);
