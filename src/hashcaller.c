#include "../include/hash.h"
#include <stdlib.h>

#define MINHASH_STRLEN 6
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

int callint()
{
  int i = 0, j = 0;
  HT *hm = NULL;
  float std_dev = 0.0;

  hashInit(&hm, cmpele, disele, HT_BST);

  for (i = 0; i < 10000; i++)
  {
    j = (rand () % 1234567);
    if(hashInsert(hm, &j, sizeof(j)) > 0)
    {
      printf("%u:value already present:", i);
      printf("%d\n", j);
      hashupdate(hm, &j, sizeof(j));
    }
  }
  for (i = 0; i < 50000; i++)
  {
    if(hashFind(hm, &i, sizeof(i)) == 0)
    {
      printf("value found:");
      disele(&i);
      printf("\n");
    }
  }

  HashAnalyse(hm, &std_dev);
  printf("std_dev: %f\n", std_dev);
  hashDestroy(&hm);
  return 0;
}

int str_display(void *data1)
{
  printf("%s", (char*)data1);
  return 0;
}

int str_compare(void *data1, void *data2)
{
  return strcmp(data1, data2);
}


int callstr()
{
  int i = 0, j = 0;
  HT *hm = NULL;
  char k[MINHASH_STRLEN] = {'\0'};
  float std_dev = 0;

  hashInit(&hm, str_compare, str_display, HT_LL);

  for (i = 1; i < 4000; i++)
  {
    for (j = 0; j < MINHASH_STRLEN - 2; j++)
    {
      k[j] = 'a' + (rand () % 26);
    }
    k[j] = 0;
    if (hashInsert(hm, &k, sizeof(k)) > 0)
    {
      printf("value already present:");
      printf("%s\n", k);
      hashupdate(hm, &k, sizeof(k));
    }
  }
  for (i = 1; i < 400000; i++)
  {
    for (j = 0; j < MINHASH_STRLEN - 2; j++)
    {
      k[j] = 'a' + (rand () % 26);
    }
    k[j] = 0;
    if (hashFind(hm, k, sizeof(k)) == 0)
    {
      printf("value found:");
      str_display(k);
      printf("\n");
    }
  }
  HashAnalyse(hm, &std_dev);
  hashDestroy(&hm);
  printf("std_dev: %f\n", std_dev);
  return 0;
}

int main()
{
  callint();
  callstr();
  
  return 0;
}

