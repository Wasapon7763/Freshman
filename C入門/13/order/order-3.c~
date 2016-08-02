#include <stdio.h>
#define N 3
void input3(int *n);
void order3(int *n);
void disp(int *n);
int main(void){
  int n[N];
  input3(n);
  disp(n);
  order3(n);
  printf("Sorted\n");
  disp(n);
}
void disp(int *n){
  int i;
  printf("Output :");
  for (i=0;i<N;i++){
    printf(" %d",*(n+i));
  }
  printf("\n");
}
void input3(int *n){
  int i;
  for (i=0;i<N;i++){
    printf("Input #%d: ",i);
    scanf("%d",n+i);
  }
}
void order3(int *n){ 
  int i,j,temp;
  for (i=0;i<N-1;i++){
    for (j=N-1;j>i;j--){
      if (n[j-1]>n[j]){
	temp=n[j-1];
	n[j-1]=n[j];
	n[j]=temp;
      }
    }
  }
}
