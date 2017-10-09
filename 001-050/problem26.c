#include <stdio.h>
#define UPPER 1000
#define SIZE 10


int longest_cycle(){
  int denom;
  int num;
  int max_cycle = 0;
  int max_cycle_denom = 0;
  int i;

  for(denom = 2; denom <= UPPER; denom++){
    int seen[UPPER] = { 0 };
    num = 1;
    i = 0;

    while(!seen[num] && num != 0){
      seen[num] = i;
      num *= 10;
      num = num % denom;
      i++;
    }

    if(i - seen[num] > max_cycle){
      max_cycle = i - seen[num];
      max_cycle_denom = denom;
    }
  }
  
return max_cycle_denom;
}


int main(void){
  int max_denom = longest_cycle();

  printf("%d\n", max_denom);

  return 0;
}

