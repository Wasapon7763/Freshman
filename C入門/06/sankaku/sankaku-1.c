#include <stdio.h>
int main(void){
  int i,j;
  for (i=0;i<9;i++){
    for (j=i+1;j>0;j--){
      printf("%d  ",j);
    }
    printf("\n");
  }
  return 0;
}
