#include <stdio.h>
int i=0;
void recur(){
  i++;
  printf("%d\n",i);
  if (i==10){
    return;
  }
  if (i<10){
    return recur();
  }
}
int main(void){
  recur();
  printf("%d",i);
  return 0;
}
