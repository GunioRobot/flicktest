#include <string.h>
#include <stdio.h>

int reverse(char *input)
{
  int i = 0, end = 0;
  char temp; 

  end = strlen(input) - 1 ;

  for (i = 0; i < strlen(input)/2; i++, end--)
  {
    temp = input[i];
    input[i] = input[end];
    input[end] = temp;
  }
  return 0;
}
int main()
{
  char input[100] = "this is newspaper's article";
  reverse(input);

  printf("string revese %s", input);
  return 0;
}
