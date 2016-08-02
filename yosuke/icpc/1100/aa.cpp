#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
  int n,count=0;
  while (cin>>n,n|n!=0){
    count++;
    int x[n];
    int y[n];
    for (int i=0;i<n;i++){
      cin>>x[i]>>y[i];
    }
    double area=0;
    for(int i=0;i<n;i++){
      area=area+(x[i]-x[(i+1)%n])*(y[i]+y[(i+1)%n]);
    }
    area=abs((double)(0.5*area));
    cout<<count<<" "<<fixed<<setprecision(1)<<area<<endl;
  }
}
