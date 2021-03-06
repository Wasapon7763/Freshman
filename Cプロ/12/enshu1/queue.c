#include <stdio.h>
#include <stdlib.h>
#define QUESIZE 100
void que_enqueue(int);
int que_dequeue(void);
int que_size(void);
int que_free(void);
int que_empty(void);
void que_clear(void);
int que[QUESIZE];
int head=0, tail=0;
void que_enqueue(int n){
  que[tail]=n;
  tail=(tail+1)%QUESIZE;
}
int que_dequeue(void){
  int n=head;
  head=(head+1)%QUESIZE;
  return que[n];
}
int que_size(void){
  if (head<tail) return tail-head;
  else return tail-head+QUESIZE;
}
int que_free(void){
  return QUESIZE-1-que_size();
}
int que_empty(void){
  return head==tail;
}
void que_clear(void){
  head=tail=0;
}
int main(void){
  int i;
  int num1=12, num2=345, num3=6789;
  char str[]="queue sample program";
  que_clear();
  que_enqueue(num1);
  que_enqueue(num2);
  que_enqueue(num3);
  printf("size=%d free=%d\n",que_size(), que_free());
  while (!que_empty()){
    printf("deque=%d \n", que_dequeue());
  }
  printf("\nenqueue.....");
  for (i=0;str[i]!='\0';i++){
    printf("%c",str[i]);
    que_enqueue(str[i]);
  }
  printf("\ndequeue.....");
  while (!que_empty()) printf("%c", que_dequeue());
  printf("\n");
  return 0;
}
