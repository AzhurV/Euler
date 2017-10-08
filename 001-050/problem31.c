#include <stdio.h>
#define N_DENOMS 8


int denominations[] = {200, 100, 50, 20, 10, 5, 2, 1};


int change(int sum, int denom_index){
  if(sum < 0 || denom_index >= N_DENOMS){
    return 0;
  }
  if(sum == 0){
    return 1;
  }
  return change(sum, denom_index + 1) +
    change(sum - denominations[denom_index], denom_index);
}


int main(void){
  int total;

  total = change(200, 0);

  printf("Ways to make change from 2 pounds: %d\n", total);

  return 0;
}
