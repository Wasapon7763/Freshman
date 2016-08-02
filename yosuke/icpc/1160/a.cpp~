#include <iostream>
#include <string>
#include <vector>
using namespace std;
int w,h;
vector<int> nx;
vector<int> ny;
bool check(int **field){
  nx.clear();
  ny.clear();
  for (int i=0;i<h;i++){
    for (int j=0;j<w;j++){
      if (field[i][j]==1){
	nx.push_back(i);
	ny.push_back(j);
	return true;
      }
    }
  }
  return false;
}
void find(int **field){
  int x[nx.size()];
  int y[ny.size()];
  int s=nx.size();
  for (int i=0;i<s;i++){
    field[nx[i]][ny[i]]=0;
    x[i]=nx[i];
    y[i]=ny[i];
  }
  nx.clear();
  ny.clear();
  for (int i=0;i<s;i++){
    if (field[x[i]+1][y[i]]==1&&x[i]+1<h){
      nx.push_back(x[i]+1);
      ny.push_back(y[i]);
    }
    if (field[x[i]-1][y[i]]==1&&x[i]-1>=0){
      nx.push_back(x[i]-1);
      ny.push_back(y[i]);
    }
    if (field[x[i]][y[i]+1]==1&&y[i]+1<w){
      nx.push_back(x[i]);
      ny.push_back(y[i]+1);
    }
    if (field[x[i]][y[i]-1]==1&&y[i]-1>=0){
      nx.push_back(x[i]);
      ny.push_back(y[i]-1);
    }
    if (field[x[i]+1][y[i]+1]==1&&x[i]+1<h&&y[i]+1<w){
      nx.push_back(x[i]+1);
      ny.push_back(y[i]+1);
    }
    if (field[x[i]+1][y[i]-1]==1&&x[i]+1<h&&y[i]-1>=0){
      nx.push_back(x[i]+1);
      ny.push_back(y[i]-1);
    }
    if (field[x[i]-1][y[i]+1]==1&&x[i]-1>=0&&y[i]+1<w){
      nx.push_back(x[i]-1);
      ny.push_back(y[i]+1);
    }
    if (field[x[i]-1][y[i]-1]==1&&x[i]-1>=0&&y[i]-1>=0){
      nx.push_back(x[i]-1);
      ny.push_back(y[i]-1);
    }
  }
  if (nx.empty()){
    return;
  }
  int *f[h];
  for (int i=0;i<h;i++)
    f[i]=field[i];
  for (int i=0;i<h;i++){
    for (int j=0;j<w;j++){
      cout<<field[i][j];
    }
    cout<<endl;
  }
  cout<<endl;
  return find(f);
}
int main(){
  while (cin>>w>>h,w|h!=0){
    int count=0;
    int field[h][w];
    for (int i=0;i<h;i++){
      for (int j=0;j<w;j++){
	cin>>field[i][j];
      }
    }
    int *f[h];
    for (int i=0;i<h;i++) 
      f[i]=field[i];
    while (check(f)){
      find(f);
      count++;
      }
    for (int i=0;i<h;i++){
      for (int j=0;j<w;j++){
	cout<<field[i][j];
      }
      cout<<endl;
    }
    cout<<count<<endl;
  }
}
