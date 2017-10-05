#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 10000

long sums[BUF_SIZE + 1] = {0};
int counted[BUF_SIZE + 1] = {0};

void populate_sums(){
  int i, divisor;
  long sum;
  for(i = 1; i <= BUF_SIZE; i++){
    sum = 0;
    for(divisor = 1; divisor <= i / 2; divisor++){
      if(i % divisor == 0){
	sum += divisor;
      }
    }
    sums[i] = sum;
  }
}

int main(int argc, char** argv){
  int i;
  long total, sum, compare_sum;
  total = 0;
  populate_sums();
  for(i = 1; i <= BUF_SIZE; i++){
    if(counted[i]){
      continue;
    }
    sum = sums[i];
    if(sum <= BUF_SIZE && !counted[sum]){
      compare_sum = sums[sum];
      if(compare_sum == i && i != sum){
	counted[i] = 1;
	counted[sum] = 1;
	total += i + sum;
      }
    }
  }
  printf("Total sum is %ld\n", total);
  exit(EXIT_SUCCESS);
}
