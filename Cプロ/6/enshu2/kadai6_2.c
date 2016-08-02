#include <stdio.h>
#include <string.h>
#include <math.h>
#define SIZE 100
int str2int(char *s){
  int l=-1,n,i,minus=1;
  while (s[l]!='\n') l++;
  if (s[0]=='-'){
    minus=-1;
    i=1;
  }
  else i=0;
  while (i<l){
    int num=s[i]-'0';
    n+=num*pow(10,l-i-1);
    i++;
  }
  return n*minus;
}
double str2double(char *s){
  int l=0,i,minus=1;
  double n;
  while (s[l]!='.') l++;
  if (s[0]=='-'){
    minus=-1;
    i=1;
  }
  else i=0;
  while (i<l){
    int num=s[i]-'0';
    n+=num*pow(10,l-i-1);
    i++;
  }
  for (i=l+1;s[i]!='\n';i++){
    int num=s[i]-'0';
    n+=num*pow(10,-(i-l));
  }
  return n*minus;
}
