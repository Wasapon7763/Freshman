#include <stdio.h>
#include <string.h>
void lower(char *s){
  int i;
  for (i=0; i<strlen(s)-1; i++){
    int n=(int)s[i];
    if (n<91&&n>64){
      s[i]=(char)(n+32);
    }
  }
}
void upper(char *s){
  int i;
  for (i=0; i<strlen(s)-1; i++){
    int n=(int)s[i];
    if (n<123&&n>96){
      s[i]=(char)(n-32);
    }
  }
}
int main(void){
  char str1[100], str2[100];
  fgets(str1, 100, stdin);
  strcpy(str2, str1);
  upper(str1);
  printf("Upper: %s", str1);
  lower(str2);
  printf("Lower: %s", str2);
  return 0;
}
