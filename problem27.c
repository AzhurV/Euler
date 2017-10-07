#include <stdio.h>
#include <math.h>
#define MAX_SIZE 1000000
#define MAX 1000
#define quadratic(n, a, b) ( (n * n) + (a * n) + (b) )

void populate_sieve(int upper, short bool_list[]){
  int j;
  for(j = 0; j < upper; j++){
    bool_list[j] = 1;
  }
  bool_list[0] = 0;
  bool_list[1] = 0;
  int test_int = 2;
  double root = sqrt(upper);
  while(test_int < root){
    int mult = test_int;
    while(mult + test_int < upper){
      mult += test_int;
      bool_list[mult] = 0;
    }
    test_int++;
    while(!bool_list[test_int] && test_int <= root){
      test_int++;
    }
  }
}

void print_primes(int n, short sieve[]){
  int i;
  for(i = 0; i < n; i++){
    if(sieve[i]){
      printf("%d is prime\n", i);
    }
  }
  return;
}


long coefficient_product(){
  int a = -999;
  int b = 2;
  long y;
  long product;
  int n;
  int cycle_seen = 0;
  short sieve[MAX_SIZE];
  
  populate_sieve(MAX_SIZE, sieve);
  
  while(a < 1000){
    while(b < 1000){
      n = 0;
      y = quadratic(n, a, b);
      while(y > 0 && sieve[y]){
	n++;
	y = quadratic(n, a, b);
      }
      if(n > cycle_seen){
	cycle_seen = n;
	product = a * b;
      }
      b++;
    }
    a++;
    b = 2;
  }

  return product;
}


int main(void){
  long product;

  product = coefficient_product();

  printf("Product of coefficients is %ld\n", product);

  return 0;
}
