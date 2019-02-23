/*
	Problem Name: Riverside Curio
	link: https://codeforces.com/contest/924/problem/C

*/

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+4;
int arr[maxn];
int t[maxn];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int cur=0;
	
	// calculate min required ti for each day
	for(int i=n-1;i>=0;i--){
		cur=max(0,cur-1);
		cur=max(cur,arr[i]+1);
		t[i]=cur;
	}
	// calculate the total number of marks on each day
	long long ans=0;
	for(int i=0;i<n;i++){
		cur =max(cur,t[i]);
		
		ans+=cur;
	}
	// ans is total number of marks of all day
	// because ti=mi+1+d
	for(int i=0;i<n;i++){
		ans-=arr[i]+1;
	}
	
	cout<<ans<<'\n';
	return 0;
}
