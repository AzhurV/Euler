#include <stdio.h>

int main()
{
  int sum_of_squares = 0;
  int sum = 0;
  int i = 0;
  for(; i <= 100; i++)
    {
      sum_of_squares += i*i;
      sum += i;      
    }
  printf("%d", sum_of_squares - sum);
  return 0;
}
