#include <stdio.h>
#define DIVISORS_COMP 500


int first_triangle(){
  int divisors;
  int i, j;
  int cur_num = 1;
  int triangle_addend = 2;

  for(; 1; cur_num += triangle_addend, triangle_addend++){
    divisors = 0;
    for(i = 1; i < cur_num; i++){
      if(cur_num % i == 0){
	j = cur_num / i;
	if(j < i){
	  break;
	}
	else{
	  divisors += 2;
	}
      }
    }
    if(divisors > DIVISORS_COMP){
      return cur_num;
    }
  }
  return -1;
}


int main(void){
  int triangle_num = first_triangle();

  printf("%d\n", triangle_num);

  return 0;
}
