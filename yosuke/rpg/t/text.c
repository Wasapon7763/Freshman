#include <stdio.h>
int main(void){
  int i=16909060;
  void *pp;
  pp=&i;
  char *p;
  p=pp;
  char c1=*p;
  char c2=*(p+1);
  char c3=*(p+2);
  char c4=*(p+3);
  printf("%d %d %d %d\n",c1,c2,c3,c4);
  return 0;
}
