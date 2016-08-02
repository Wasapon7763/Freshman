#include <stdio.h>
#include <stdlib.h>
char *num2str(int i){
  char *str;
  str=(char *)malloc(sizeof(char)*30);
  if (str==NULL){
    printf("error");
    exit(1);
  }
  sprintf(str, "%d", i);
  return str;
}
int main(void){
  int num1, num2;
  printf("Input number 1: ");
  scanf("%d", &num1);
  printf("Input number 2: ");
  scanf("%d", &num2);
  printf("%s %s\n", num2str(num1), num2str(num2));
  return 0;
}
