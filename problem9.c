#include <stdio.h>
#include <math.h>

int pythagorean_triplet_prod(int sum)
{
  int a, b, c;
  for(a = 1;;a++)
    {
      for(b = 1; b < a; b++)
	{
	  c = sqrt(a*a + b*b);
	  if ((a + b + c) == sum)
	    return a*b*c;
	}
    }
  
}

int main()
{
  int sum;
  printf("Enter the desired sum: ");
  scanf("%d", &sum);
  int product = pythagorean_triplet_prod(sum);
  printf("Product abc is: %d\n", product);
  return 0;
}
