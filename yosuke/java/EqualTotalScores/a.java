import java.io.*;
import java.util.*;
public class a{
    public static void main(String args[]){
	while(true){
	    int n,m,t_total=0,h_total=0;
	    Scanner kb=new Scanner(System.in);
	    n=kb.nextInt();
	    m=kb.nextInt();
	    if (n==0&&m==0){
		break;
	    }
	    int taro[]=new int[n];
	    int hana[]=new int[m];
	    for (int i=0;i<n;i++){
		taro[i]=kb.nextInt();
		t_total+=taro[i];
	    }
	    for (int i=0;i<m;i++){
		hana[i]=kb.nextInt();
		h_total+=hana[i];
	    }
	    int s,p,r,minn=51,minm=51;
	    for (int i=0;i<n;i++){
		s=t_total-taro[i];
		for (int j=0;j<m;j++){
		    r=s+hana[j];
		    p=h_total-hana[j]+taro[i];
		    if (r==p&&r+p<minn+minm){
			minn=i+1;
			minm=n+j+1;
		    }
			
		}
	    }
	    System.out.println(minn+" "+minm);
	}
    }
}