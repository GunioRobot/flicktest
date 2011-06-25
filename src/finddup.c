#include <stdio.h>

int main()
{
  char s1[] ="ABCDEFGHIJKGHIG";//"ABCDCDEF";
  char s2[]="GHIJKXYZ";// "CDEFGHI";
  char s3[100];
  char *p1;
  char *p2;
  p1= s1;
  p2 =s2;
  int i =0;
  printf("%s \n %s \n", s1, s2);

  while(*p1 )
  {
    if(*p1 != *p2)
    {
      s3[i++] = *p1;
      p1++;

    }
    if(*p1 == *p2)
    {
      s3[i++] = *p1;
      p1++;
      p2++;
    }

  }
  while(*p2)
  {
    s3[i++] = *p2;
    p2++;
  }
  s3[i] = '\0';
  printf("string is %s\n",s3);
} 
