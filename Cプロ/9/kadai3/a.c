#include <stdio.h>
#include <stdlib.h>
char *num2str(int i){
  char str[30];
  char *p=str;
  p+=30*i;
  *p=str[0];
  //char *str;
  //str=(char *)malloc(sizeof(char)*30);
  sprintf(str, "%d", i);
  printf("%p  %s\n",p,p);
  return p;
}
int main(void){
  int num1, num2,i=2;
  printf("Input number 1: ");
  scanf("%d", &num1);
  printf("Input number 2: ");
  scanf("%d", &num2);
  //printf("%s %s\n",num2str(num1),num2str(num2));
  printf("%p %p %p\n",num2str(num1),num2str(num2),num2str(i));
  return 0;
}
//str[30]だと返すアドレスが変わらなくなってしまう。一度strを配列として宣言してしまったら、その配列のアドレスは一定となる。mallocを使うと、strはchar型30要素分のアドレスとして宣言されるため、strは毎回違うポインタとして扱われる。よって、返すアドレスの値も毎回違う。
