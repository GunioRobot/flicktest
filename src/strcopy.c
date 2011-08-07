#include <stdio.h>

char* mystrcpy(char *dest, const char *src)
{
  char *temp = dest;

  while(*src != '\0')
  {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = '\0';
  return temp;
}

int main()
{
  char input[100] = "this is the original string", output[100];

  mystrcpy(output, input);
  printf("dest string %s\n", output);
  return 0;
}
