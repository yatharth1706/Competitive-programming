/*
	problem name: Polycarp loves permutation
	problem link: https://codeforces.com/contest/1141/problem/C

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main(){
	boost;
	int n;
	cin>>n;
	ll q[n-1];
	ll sum=0;
	ll minSum=0;
	for(int i=0;i+1<n;i++){
		cin>>q[i];
		sum+=q[i];
		if(sum<minSum){
			minSum=sum;
		}
	}
	
	ll x=1-minSum;
	ll p[n];
	p[0]=x;
	for(int i=1;i<n;i++){
		p[i]=p[i-1]+q[i-1];
	}
	bool flag=true;
	for(int i=0;i<n;i++){
		if(p[i]>n || p[i]<1){
			flag=false;
			break;
		}
	}
	
	if(flag){
		set<ll> s;
		for(int i=0;i<n;i++){
			s.insert(p[i]);
		}
		flag= s.size()==n;
	}
	
	if(flag){
		for(int i=0;i<n;i++){
			cout<<p[i]<<' ';
		}
	}
	else{
		cout<<-1<<'\n';
	}	
	return 0;
}
