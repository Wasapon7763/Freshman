#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n;
  vector<int> num;
  while (cin>>n,n|n!=0){
    num.push_back(n);
  }
  int i=0;
  while (cin>>n,n|n!=0){
    if (n!=num[i]){
      cout<<i<<endl;
    }
    i++;
  }
}
