int main()
{
  double i = 2.0, j = 1.0, sum = 0.0;

  while(i/j > 0.001)
  {
    j = j + j;
    sum = sum + (i/j);
    printf("sum %f j %f\n", sum, j);
  }
  return 0;
}
