#include <string.h>
#include <stdio.h>

char *strreveser(char *input)
{
  char c = 0;
  int i = 0, end = 0;

  end = strlen(input)-1;

  for (i = 0; i < strlen(input)/2; i++)
  {
    c = input[i];
    input[i] = input[end-i];
    input[end-i] = c;
  }
  return 0;
}

int revwords(char *word, unsigned int len)
{
  int i = 0;
  char c = 0;

  while(len/2 > i)
  {
    c = word[i];
    word[i] = word[len-i-1];
    word[len-i-1] = c;

    i++;
  }

  return 0;
}
int main()
{
  char input[100] = "this is newinput 123456789 string";
  char *c = NULL, *org = NULL;
  int len = 0;


  printf("%s\n", input);
  strreveser(input);
  printf("%s\n", input);

  c = input;

  while(*c != '\0')
  {
    len = 0;
    org = c;

    while(*c != ' ' && *c != '\0')
    {
      len++;
      c++;
    }
    revwords(org, len);
    c++;
  }
  printf("%s\n", input);
  return 0;
}
