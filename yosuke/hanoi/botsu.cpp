#include <iostream>
#include <stdio.h>
#include <string>
#define N 5
using namespace std;
void disp(int num[N][3]){
  cout<<endl;
  for (int i=0;i<3;i++){
    cout<<i+1;
    for (int j=0;j<N;j++){
      cout<<" ";
    }
  }
  cout<<endl;
  for (int i=0;i<N;i++){
    for (int j=0;j<3;j++){
      for (int l=0;l<num[i][j];l++){
	cout<<"-";
      }
      for (int l=0;l<N+1-num[i][j];l++){
	cout<<" ";
      }
    }
    cout<<endl;
  }
}
void desc(){
  cout<<endl<<"x:select location"<<endl<<"y:how many to move"<<endl<<"z:where to move"<<endl;
}
void show(int num[N][3]){
  for (int i=0;i<N;i++){
    for (int j=0;j<3;j++){
      cout<<num[i][j]<<" ";
    }
    cout<<endl;
  }
}
int main(){
  int num[N][3]={0};
  for (int i=0;i<N;i++){
    num[i][0]=i+1;
  }
  while (1){
    disp(num);
    cout<<endl<<"Input move (x y z). Input 0 0 0 to show description"<<endl<<">>";
    int loc,fr,to,hoge;
    cin>>loc>>fr>>to;
    if (loc==0)
      desc();
    show(num);
    int tozero,frzero;
    for (int i=0;i<N;i++){
      if (num[i][loc-1]==fr){
	hoge=i;
	break;
      }
    }
    for (int i=N-1;i>=0;i--){
      if (num[i][loc-1]==0){
	frzero=i;
	break;
      }
    }
    if (hoge!=frzero-1){
      goto lbl;
    }
    for (int i=N-1;i>=0;i--){
      // cout<<i<<" ";
      if (num[i][to-1]==0){
	tozero=i;
	break;
      }
    }
    for (int i=N-1;i>=0;i--){
      if (num[i][loc-1]==fr){
	frzero=i;
	break;
      }
    }
    cout<<hoge<<frzero<<endl;
    if (fr>=num[tozero+1][to-1]&&tozero+1!=N)
      continue;
    for (int i=0;i<fr;i++){
      num[tozero][to-1]=num[frzero][loc-1];
      num[frzero][loc-1]=0;
      tozero--;
      frzero--;
    }
  lbl:;
  }
  return 0;
}
