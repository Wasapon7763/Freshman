#include <stdio.h>
#include <string.h>
int main(void){
  char c[50];
  fgets(c,50,stdin);
  int i=0;
  while(c[i]!='\0'){
    i++;
  }
  printf("%d",i);
}
