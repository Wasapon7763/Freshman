#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
  int n,count=0;
  while (cin>>n,n|n!=0){
    count++;
    vector<int> xvalue;
    vector<int> yvalue;
    double area=0;
    double temp;
    int x,y;
    for (int i=0;i<n;i++){
      cin>>x>>y;
      xvalue.push_back(x);
      yvalue.push_back(y);
    }
    x=0;
    y=0;
    int xcenter,ycenter;
    for (int i=0;i<n;i++){
      x=x+xvalue[i];
      y=y+yvalue[i];
    }
    xcenter=x/n;
    ycenter=y/n;
    int x1,x2,y1,y2;
    for (int i=0;i<n;i++){
      x1=xvalue[i]-xcenter;
      y1=yvalue[i]-ycenter;
      x2=xvalue[(i+1)%n]-xcenter;
      y2=yvalue[(i+1)%n]-ycenter;
      area=area+0.5*abs((double)(x1*y2-x2*y1));
    }
    cout<<count<<" "<<fixed<<setprecision(1)<<area<<endl;
  }
}
