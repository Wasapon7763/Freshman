#include <stdio.h>
int main(void){
  double h,w,bmi;
  printf("Input your height[cm]: ");
  scanf("%lf",&h);
  printf("Input your weight[kb]; ");
  scanf("%lf",&w);
  bmi=(w/(h*h))*10000;
  if (bmi<18.5){
    printf("Your BMI is %2.1f. Underweight\n",bmi);
  }
  else if((bmi<25)&&(bmi>=18.5)){
      printf("Your BMI is %2.1f. Normal\n",bmi);
  }
  else if((bmi<30)&&(bmi>-25)){
	printf("Your BMI is %2.1f. Pre-obese\n",bmi);
      }
      else if(bmi>=30){
	printf("Your BMI is %2.1f. Obese class\n",bmi);
      }
  return 0;
}
