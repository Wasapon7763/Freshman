#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

double integral(int n){
	int i;
	int count = 0;
	double x, y;
	double res;

	srand((unsigned)time(NULL));

	/* ここから編集 */
	for (i=0;i<n;i++){
	  x=(double)rand()/RAND_MAX;
	  y=(double)rand()/RAND_MAX;
	  if (sqrt(x*x+y*y)<1){
	    count++;
	  }
	}
	res=4*count/(n+0.0);
	/* ここまで編集 */

	return res;
}

int main(void){
	int n;

	printf("Input the number of points :");
	scanf("%d", &n);

	printf("S=%f\n", integral(n));

	return 0;
}
