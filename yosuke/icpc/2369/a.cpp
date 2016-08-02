#include <iostream>
#include <string>
#include <vector>
using namespace std;
string ss;
void check(string s){
  if (s=="mew"){
    cout<<"Cat"<<endl;
    return ;
  }
  for (int i=0;i<s.length()-2;i++){
    if (s[i]=='m'&&s[i+1]=='e'&&s[i+2]=='w'){
      s[i]=' ';
      s[i+1]=' ';
      s[i+2]=' ';
    }
  }
  int l=s.length();
  for (int i=0;i<l;i++){
    if (s[i]==' '){
      for (int j=i;j<l;j++){
	s[j]=s[j+3];
      }
	s.erase(l-3,l);
      l-=3;
    }
  }
  if (s=="mew"){
    cout<<"Cat"<<endl;
    return ;
  }
  if (s.empty()||s==ss){
    cout<<"Rabbit"<<endl;
    return ;
  }
  ss=s;
  return check(s);
}
int main(){
  string s;
  cin>>s;
  check(s);
}
