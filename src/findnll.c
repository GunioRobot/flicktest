#include <stdio.h>
#include <stdlib.h>

typedef struct LL
{
  int value;
  struct LL *next;
}LL;

int LLadd(LL **head, int value)
{
  LL *temp = NULL;

  if (head == NULL)
    return -1;

  if (*head == NULL)
  {
    temp = (LL*)malloc(sizeof(LL));
    if (temp == NULL)
      return -1;

    temp->value = value;
    temp->next = NULL;
    *head = temp;
    /* first node */
  }
  else
  {
    temp = *head;
    while (temp->next != NULL)
    {
      temp  = temp->next;
    }

    temp->next = (LL*)malloc(sizeof(LL));
    if (temp == NULL)
      return -1;

    temp->next->value = value;
    temp->next->next = NULL;
  }

  return 0;
}

int findnth(LL *head, int n)
{
  while (head)
  {
    head = head->next;
    n--;
    if (n == 0)
    {
      printf("%d", head->value);
      return 0;
    }
  }
  return 1;
}

int main()
{
  int i = 0, n = 5;

  LL *head = NULL;

  for (i = 0; i < 3; i++)
  {
    LLadd(&head, i);
  }

  findnth(head, n);

  return 0;
}
