#include <stdio.h>
#include <math.h>
#define NUM 600851475143

long largestPrime(long n){
  long max = (long) sqrt(n);
  long i;
  for(i = 2; i <= max; i++){
    while(n % i == 0){
      n = (long) n / i;
      if(n == i || n == 1){
	return i;
    }
    }
  }
  return -1;
}
    

int main(void){
  long n = NUM;
  long primeFactor = largestPrime(n);
  printf("Largest factor of %ld is %ld\n", n, primeFactor);

  return 0;
}
