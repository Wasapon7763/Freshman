#include <stdio.h>
int main(void){
  long l;
  long double d;
  int i,k,n;
  scanf("%d",&n);
  for (k=1;k<=n;k++){
    d=1;
    l=1;
    for (i=1;i<=k;i++){
      d*=i;
      l*=i;
    }
    printf("long  :%d!=%ld\n",k,l);
    printf("double:%d!=%Lf\n\n",k,d);
  }
  return 0;
}
