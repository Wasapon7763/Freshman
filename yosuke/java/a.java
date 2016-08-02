import java.io.*;
import java.util.*;
import java.lang.Math;
public class a{
    public static void main(String args[]){
	Scanner sc=new Scanner(System.in);
	double a,b,c;
	System.out.print("a=");
	a=sc.nextDouble();
	System.out.print("b=");
	b=sc.nextDouble();
	System.out.print("c=");
	c=sc.nextDouble();
	System.out.print(((-b+Math.sqrt(b*b-4*a*c))/2*a));
    }
}