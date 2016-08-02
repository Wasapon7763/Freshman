#include <stdio.h>
void selectsort(int *a, int n){
  int i,j,min,hoge;
  for (j=1;j<n-1;j++){
    min=j;
    for (i=j+1;i<n;i++){
      if (a[min]>a[i])
	min=i;
    }
    if (a[j-1]>a[min]){
      hoge=a[j-1];
      a[j-1]=a[min];
      a[min]=hoge;
    }
  }
}
int n=0;
void quick_sort(int *a, int left, int right){
  int i,j,ii=0,jj=0,key,hoge,boo=0;
  while (1){
    key=(left+right)/2;
    for (i=left+ii;i<key&&a[key]>a[i];i++){
    }
    for (j=right+jj;j>key&&a[key]<a[j];j--){
    }
    if (i<j&&i!=key&&j!=key){
      hoge=a[i];
      a[i]=a[j];
      a[j]=hoge;
      ii++;
      jj--;
    }
    if (left+ii==right+jj)
      break;
    if ((i==key||j==key)&&!(i==key&&j==key)){
      hoge=a[i];
      a[i]=a[j];
      a[j]=hoge;
      boo=1;
      break;
    }
    if (i==key&&j==key)
      break;
  }
  if (boo==1){
    printf("a %d %d\n",left,right);
    quick_sort(a,left,right);
  }
  if (i+1>=2){
    printf("b %d %d",left, right);
    quick_sort(a,left,i);
  }
  if (right-j+1>=2){
    n++;
    printf(" %d ",j);
    quick_sort(a,j,right);
  }
}
