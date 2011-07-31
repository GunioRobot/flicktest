#include <stdio.h>

int main()
{
  int input = 123, value = 0;
  int i = 0;
  char output[33];

  for (i = 0; i < sizeof(input)*8; i++)
  {
    value = input >> i;
    if (value % 2 == 1)
    {
      output[31-i] = '1';
    }
    else
    {
      output[31-i] = '0';
    }
  }
  output[32] = '\0';
  printf("%s\n", output);
  return 0;
}
