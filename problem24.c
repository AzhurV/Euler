#include <stdio.h>
#define SIZE 10
#define PERMUTATION_N 1000000


void swap(int array[SIZE], int i, int j){
  int temp;
  temp = array[i];
  array[i] = array[j];
  array[j] = temp;
  return;
}


int swapMin(int array[SIZE], int swapIndex){
  if(swapIndex >= SIZE - 1){
    return 0;
  }
  int minIndex = swapIndex;
  int i;
  for(i = swapIndex; i < SIZE; i++){
    if(array[i] < array[minIndex]){
      minIndex = i;
    }
  }
  swap(array, swapIndex, minIndex);
  return 1;
}


int swapMinGreater(int array[SIZE], int swapIndex){
  if(swapIndex >= SIZE - 1){
    return 0;
  }
  int minIndex = swapIndex + 1;
  int i;
  for(i = swapIndex + 1; i < SIZE; i++){
    if(array[i] < array[minIndex] && array[i] > array[swapIndex]){
      minIndex = i;
    }
  }
  if(array[minIndex] < array[swapIndex]){
    return 0;
  }
  swap(array, swapIndex, minIndex);
  return 1;
}


void generatenthPermutation(int array[SIZE], long long n){
  long long curPerm = 1;
  int i;
  while(curPerm != n){
    i = SIZE - 1;
    while(!swapMinGreater(array, i) && i >= 0){
      i--;
    };
    i++;
    for(; i < SIZE; i++){
      swapMin(array, i);
    }
    curPerm++;
  }
  return;
}



int main(void){
  int original[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  
  generatenthPermutation(original, PERMUTATION_N);

  int i;
  for(i = 0; i < SIZE; i++){
    printf("%d", original[i]);
  }
  printf("\n");
  
  return 0;
}

