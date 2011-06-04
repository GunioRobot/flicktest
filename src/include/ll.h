#include <stdio.h>
#include <malloc.h>
#include <string.h>

//typedef  int (*comparell) (const void *, const void *);

typedef struct LLmeta
{
  unsigned int count;
  struct LL    *head;
  struct LL    *tail;
  int (*fptr) (const void *, const void *);
}LLmeta;

typedef struct LL
{
  //int value;
  void *element;
  struct LL *next;
  struct LL *prev;
  //struct LL *right;
}LL;


int LLinit(LLmeta**, int (*fptr)(const void *, const void *));

LL* LLappend(LLmeta *, void *, unsigned int );

int LLdelete(LLmeta *, void *, int (*fptr)(const void *, const void *)); 

int LLtraverse(LL *);

LL* LLfind(LLmeta*, LL *,  void *, int (*fptr)(const void *, const void *));

