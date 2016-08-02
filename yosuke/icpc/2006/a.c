#include <stdio.h>
int main(void){
  int key[10]={0,1,2,3,4,5,6,7,8,9};
  char one[5]={'.',',','!','?',' '};
  char two[3]={'a','b','c'};
  char three[3]={'d','e','f'};
  char four[3]={'g','h','i'};
  char five[3]={'j','k','l'};
  char six[3]={'m','n','o'};
  char seven[4]={'p','q','r','s'};
  char eight[3]={'t','u','v'};
  char nine[4]={'w','x','y','z'};
  while (1){
    char s[1024];
    scanf("%s",s);
    char *pa;
    pa=&(nine[0]);
    printf("%s\n",pa);
  }
  return 0;
}
