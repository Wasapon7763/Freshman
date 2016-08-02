#include <stdio.h>
typedef struct{
  char title[30];
  int pages;
  int id;
}BOOK;
BOOK item[8]={
  {"English Reading", 110, 980},
  {"C Prog.", 218, 3000},
  {"Perl Prog.", 120, 1800},
  {"C++ Prog.", 360, 4500},
  {"Pascal Prog.", 190, 2200},
  {"Lisp Prog.", 150, 1700},
  {"JAVA Prog.", 200, 2900},
  {"C# Prog.", 240, 3800}};
int item_num=10;
int linear_s_banpei(BOOK ary[], int n, int key){
  int i=0,last=-1;
  if (n==item_num){
    n--;
    last=ary[n].id;
    if (last==key){
      return n;
    }
  }
  ary[n].id=key;
  while (ary[i].id!=key) ++i;
  if (i<n){
    ary[n].id=last;
    return i;
  }
  else{
    ary[n].id=last;
    return -1;
  }
}
int main(void){
  int ret;
  ret=linear_s_banpei(item, item_num, 1700);
  if (ret==-1) printf("not found\n");
  else printf("id=%d, name=%s\n", ret, item[ret].title);
  return 0;
}
