#include "../include/ll.h"
#include <stdlib.h>
#include <time.h>

#define LL_STRLEN 10
int disele(const void *ele1)
{
  if (ele1 == NULL)
    return 1;
  printf("%d ", *(int*)ele1);
    return 0;
}


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

int inLL()
{
  LLmeta *lm = NULL;
  int i = 0;

  LLinit(&lm, cmpele, disele);

  for (i = 0; i <30; i++)
    LLappend(lm, &i, sizeof(i));

  for (i = 0; i <30; i+=3)
    LLdelete(lm, &i);

  LLtraverse(lm);
  return 0;
}

int diselestr(const void *ele1)
{
  if (ele1 == NULL)
    return 1;
  printf("%s ", (char*)ele1);
    return 0;
}


int cmpelestr(const void *ele, const void *value)
{
  if (ele == NULL || value == NULL)
    return 1;
  else
    return strcmp((char*)ele, (char*)value);
}

int inLLstr()
{
  LLmeta       *lm           = NULL;
  int           i            = 0, j = 0;
  char          k[LL_STRLEN];
  unsigned int  iseed        = (unsigned int)time(NULL);

  srand (iseed);
  LLinit(&lm, cmpelestr, diselestr);

  for (i = 0; i <30; i++)
  {
    for (j = 0; j < LL_STRLEN-2; j++)
    {
      k[j] = 'a' + (rand () % 26);
    }
    k[j] = 0;
    LLappend(lm, (void*)k, sizeof(k));
  }

  LLtraverse(lm);
  return 0;
}


int main()
{
  inLL();
  inLLstr();
  return 0;
}

