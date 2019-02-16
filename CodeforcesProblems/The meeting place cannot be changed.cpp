/*

Problem link: https://codeforces.com/contest/782/problem/B

Problem name: The Meeting Place Cannot Be Changed

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
# define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ll arr[60010],v[60010],n;

bool isok(double m){
	double l,r;
	l=-1e9;r=1e18;
	for(int i=0;i<n;i++){
		l=max(l,arr[i]-v[i]*m);
		r=min(r,arr[i]+v[i]*m);
	}
	if(r>l){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	boost
	
	
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	
	double l,r;
	l=0; r=1e9+10;
	while(r-l>1e-6){
		double mid=(l+r)/2;
		if(isok(mid)){
			r=mid;
		}
		else{
			l=mid;
		}
	}
	cout<<std::fixed<<setprecision(12)<<l<<'\n';
	return 0;
}
