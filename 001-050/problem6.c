#include <stdio.h>

int main()
{
  long sum_of_squares = 0;
  long  sum = 0;
  int i;
  for(i = 1; i <= 100; i++)
    {
      sum_of_squares += i * i;
      sum += i;      
    }
  printf("%ld\n", sum * sum - sum_of_squares);
  return 0;
}
