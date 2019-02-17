/*
	problem link: https://codeforces.com/contest/404/problem/B
	problem name: Marathon

*/
#include<bits/stdc++.h>
using namespace std;
double a,d,prod;
//int level(double n){
//	prod=a;
//	int c=1;
//	while(prod<=n){
//		c++;
//		prod+=a;
//		if(c>4){
//			c=1;
//		}
//	}
//	return c;
//}
int main(){
	cin>>a>>d;
	double n;
	cin>>n;
	double cur=d,x,y,d3,yv;
	d3=0;
	yv=0;
	for(int i=1;i<=n;i++){
		d3=fmod(d3+d,4*a);
		
		if(3*a<=d3){
			printf("%.10f %.10f\n",yv,a-fmod(d3,3*a));
		}
		else if(2*a<=d3){
			printf("%.10f %.10f\n",a-fmod(d3,2*a),a);
		}
		else if(1*a<=d3){
			printf("%.10f %.10f\n",a,fmod(d3,a));
		}
		else{
			printf("%.10f %.10f\n",fmod(d3,a),yv);
		}
	}
	
	return 0;
}
