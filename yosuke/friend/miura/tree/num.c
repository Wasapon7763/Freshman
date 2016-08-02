#include <stdio.h>
#include <stdlib.h>
typedef struct _num{
  int n;
  char* number;
  struct _num* next;
}Number;
void show(Number* num){
  while (num){
    printf("%s\n",num->number);
    num=num->next;
  }
}
int main(void){
  Number one={1,"1",NULL};
  Number two={2,"2",NULL};
  Number three={3,"3",NULL};
  one.next=&two;
  two.next=NULL;
  show(&one);
  return 0;
}
