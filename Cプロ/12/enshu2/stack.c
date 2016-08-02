#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define STKSIZE 100
int stack[STKSIZE];
int sp=0;
void stk_push(int n){
  if (sp==STKSIZE){
    printf("stack over flow\n");
    exit(1);
  }
  stack[sp++]=n;
}
int stk_pop(void){
  if (sp==0){
    printf("stack underflow\n");
    exit(1);
  }
  return stack[--sp];
}
int stk_top(void){
  if(sp==0){
    printf("no data\n");
    exit(1);
  }
  return stack[sp-1];
}
int stk_size(void){
  return sp;
}
int stk_free(void){
  return STKSIZE-sp;
}
int stk_empty(void){
  return sp==0;
}
void stk_clear(void){
  sp=0;
}
