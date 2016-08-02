#include <stdio.h>
#include <string.h>
#define MAXLINE 100

int str_len(char *s){
  int i=0;
  while (s[i]!='\0')
    i++;
  return i-1;
}
void str_cpy(char *s1, char *s2){
  int i=0;
  while (s2[i]!='\0'){
    s1[i]=s2[i];
    i++;
  }
  s1[i]='\0';
}
