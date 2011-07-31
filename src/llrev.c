#include <stdio.h>
#include <stdlib.h>

typedef struct LL
{
  int value;
  struct LL *next;
}LL;

int LLadd(LL** head, int i)
{
  LL *temp = NULL;

  if (head == NULL)
    return 1;

  if (*head == NULL)
  {
    /* first node */
    temp = (LL*)malloc(sizeof(LL));
    temp->value = i;
    temp->next = NULL;
    *head = temp;
  }
  else
  {
    temp = (*head);
    while (temp->next)
    {
      temp = temp->next;
    }
    temp->next = (LL*)malloc(sizeof(LL));
    temp->next->value = i;
    temp->next->next = NULL;
  }
  return 0;
}

int LLtraverse(LL *head)
{
  while(head)
  {
    printf("%d ", head->value);
    head = head->next;
  }
  return 0;
}
int LLrev(LL *head, LL **orig_head)
{
  if (head == NULL)
    return 1;

  if (head->next == NULL)
  {
    *orig_head = head;
    return 0;
  }
  else
  {
    LLrev(head->next, orig_head);
    head->next->next = head;
  }
  return 0;
}
int LLreverse(LL *head, LL **orig_head)
{
  LL *temp = head;
  LLrev(head, orig_head);

  if (temp)
  {
    temp->next = NULL;
  }
  return 0;
}

int main()
{
  LL *head = NULL;
  int i = 0;

  for (i = 0; i < 3; i++)
  {
    LLadd(&head, i);
  }

  LLtraverse(head);
  LLreverse(head, &head);
  printf("\n");
  LLtraverse(head);
  return 0;
}
