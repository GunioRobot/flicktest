#include <stdio.h>
#include <string.h>

int ispalindrom(char *str, unsigned int len)
{
  char *tmp = str + len - 1;
  len = len / 2;

  while (*tmp == *str)
  {
    if (len == 0)
      return 0;

    len --;
    tmp--;
    str++;
  }
  return 1;
}
int main()
{
  char str[100] = "abcecba";
  printf("%d", ispalindrom(str, strlen(str)));
  return 0;
}
