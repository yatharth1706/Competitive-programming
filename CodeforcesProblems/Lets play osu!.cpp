/*
	problem name: Lets play OSU!
	problem link:https://codeforces.com/contest/235/problem/B
	algorithm: dynamic programming

*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
double dp[maxn];
int main(){
	int n;
	cin>>n;
	double arr[n]; // for probability
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	dp[0]=0; // it will store sum of all the events (i,j) which means s[i]='o' and s[j]='o'
	double s=arr[0];
	for(int j=1;j<n;j++){
		dp[j]=(dp[j-1]+arr[j-1])*arr[j];
		s+=dp[j]*2 + arr[j];
	}
	cout<<std::fixed<<setprecision(15)<<s<<'\n';
	
	return 0;
}
