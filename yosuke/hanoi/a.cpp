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
int check(int num[N][3]){
  for (int i=0;i<N;i++){
    if (num[i][2]!=i+1){
      return 0;
    }
  }
  return 1;
}
int main(){
  int num[N][3]={0};
  for (int i=0;i<N;i++){
    num[i][0]=i+1;
  }
  int count=0;
  while (1){
    disp(num);
    cout<<"count: "<<count<<endl;
    cout<<endl<<"Input move (x y z). Input 0 0 0 to show description"<<endl<<">>";
    int a,b,zr,n=-1;
    cin>>a>>b;
    if (a==0)
      desc();
    //show(num);
    for (int i=0;i<N;i++){
      if (num[i][b-1]!=0){
	zr=i;
	break;
      }
      zr=N;
    }
    for (int i=0;i<N;i++){
      if (num[i][a-1]!=0){
	n=i;
	break;
      }
    }
    //cout<<n<<zr<<endl;
    if (num[n][a-1]<num[zr][b-1]&&n!=-1&&zr!=N&&a<4&&b<4){
      num[zr-1][b-1]=num[n][a-1];
      num[n][a-1]=0;
    }
    if (zr==N&&n!=-1&&a<4&&b<4){
      num[zr-1][b-1]=num[n][a-1];
      num[n][a-1]=0;
    }
    //cout<<check(num)<<endl;
    if (check(num)==1){
      disp(num);
      cout<<endl<<"    win"<<endl;
      break;
    }
    count++;
  }
  return 0;
}
