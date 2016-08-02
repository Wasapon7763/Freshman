#include <stdio.h>
#include <stdlib.h>
#include "que.h"
#define QUESIZE 100
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

