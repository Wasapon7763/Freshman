#include <stdio.h>
int main(void){
  int i,j,n;
  for (i=1;i<10;i++){
    for (j=1;j<10;j++){
      n=i*j;
      if (n<10){
	printf("  %d",n);
      }
      else{
	printf(" %d",n);
      }
    }
    printf("\n");
  }
  return 0;
}
