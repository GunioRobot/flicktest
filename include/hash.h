#include <stdio.h>
#include <malloc.h>
#include "ll.h"
#include "bst.h"
#define HT_SIZE 1024

#define HT_SUCC 0
#define HT_FAIL 1


#define HT_BST 1
#define HT_LL  2


typedef struct HT
{
  LLmeta   *lm[HT_SIZE];
  bst_meta *bm[HT_SIZE];
  int      count;
  int    (*cmp)(void*, void*); /* compare function pointer  */
  int    (*dis)(void*);        /* display function pointer. */
  unsigned int type;
}HT;

HT* hashInit();

unsigned int hashgen(unsigned char *value, size_t vsize);

int hashInsert(HT *htmeta, void *value, size_t vsize);

int hashFind(HT *ht, void *value, unsigned int vsize);

int HashAnalyse(HT *ht, float *sdev); 

int hashDestroy(HT **hm);
