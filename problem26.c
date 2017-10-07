#include <stdio.h>
#define MAX_CYCLE 1000


void zero_out(int size, int buf[size]){
  int i;
  for(i = 0; i < size; i++){
    buf[i] = 0;
  }
  return;
}


int longest_cycle(int n){
  int buf[n];
  int max_seq_len = 0;
  int denom;
  int cur_val, cur_pos;

  for(denom = n; denom > 1; denom--){
    if(max_seq_len >= denom){
      break;
    }
    
    cur_val = 1;
    cur_pos = 0;

    while(buf[cur_val] == 0 && cur_val != 0){
      buf[cur_val] = cur_pos;
      cur_val *= 10;
      cur_val %= denom;
      cur_pos++;
    }

    if(cur_pos - buf[cur_val] > max_seq_len){
      max_seq_len = cur_pos - buf[cur_val];
    }
    zero_out(n, buf);
  }
  return max_seq_len;
}


int main(){
  int cycle_size;
  cycle_size = longest_cycle(MAX_CYCLE);
  printf("Longest cycle is %d\n", cycle_size);

  return 0;
}
