#include <stdio.h>
int bin_search(int ary[], int n, int key){
  int left, right, mid, count, boo=0;
  left=0;
  right=n-1;
  while (left<=right){
    mid=(left+right)/2;
    if (ary[mid]>key){
      right=mid;
      if (mid==1&&ary[left]==key){
	return left;
      }
    }
    else if (ary[mid]<key){
      left=mid;
      if (mid==n-2&&ary[right]==key){
	return right;
      }
    }
    else if (ary[mid]==key||ary[right]==key||ary[left]==key)
      return mid;//mid==key
    if (mid==count){
      boo++;
    }
    if (boo>1) break;
    count=mid;
  }
  return -1;
}
int main(void){
  int key;
  int data[14]={5,10,15,20,25,30,35,40,45,50,55,60,65,70};
  for (key=10; key<=70; key+=10){
    printf("data=%d ret=%d\n", key, bin_search(data,14,key));
  }
  return 0;
}
