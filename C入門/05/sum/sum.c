#include<stdio.h>
int main(void){
  int i,n,ans=0;
  printf("Input number N=: ");
  scanf("%d",&n);
  for (i=1;i<n+1;i++){
    ans=ans+2*i-1;
  }
  printf("Answer is %d.\n",ans);
  return 0;
}
