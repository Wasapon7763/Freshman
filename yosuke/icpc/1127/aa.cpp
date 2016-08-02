#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
  vector<int> prime;		  
  for (int i=2;i<247000;i++){
    int count=0;
    int j;
    if (i%2!=0||(sqrt(i)-(int)sqrt(i))!=0){
      for (j=2;j<i/2;j++){
	if (i%j==0){
	  break;
	}
      }
    }
    if ((j==i/2||i==2||i==3)&&i!=4){
      prime.push_back(i);
    }
  }
  int n;
  while (cin>>n,n|n!=0){
    int i=0;
    int s;
    while (1){
      if (n<prime[i]){
	s=i;
	break;
      }
      i++;
    }
    int e;
    while (1){
      if (2*n<prime[i]){
	e=i-1;
	break;
      }
      i++;
    }
    cout<<e-s+1<<endl;
  }
}
