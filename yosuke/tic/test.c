#include <stdio.h>
int main(void){
  int i,j;
  for (i=0;i<5;i++){
    for (j=0;j<5;j++){
      printf("%d ",j);
      if (j==i){
	break;
      }
    }
    printf("\n");
  }
  return 0;
}
