/*
Problem link: https://codeforces.com/problemset/problem/776/B
Problem Name: Sherlock and his girlfriend
*/
#include<bits/stdc++.h>
using namespace std;
int arr[10000001];
int main(){
	int n;
	cin>>n;
	for(int i=2;i<=n+1;i++){
		if(!arr[i]){
			for(int j=2*i;j<=n+1;j+=i){
				arr[j]=1;
			}
		}
	}
	if(n>2){
		cout<<"2"<<'\n';
	}
	else{
		cout<<"1"<<'\n';
	}
	for(int i=2;i<=n+1;i++){
		if(!arr[i]){
			cout<<"1 ";
		}
		else{
			cout<<"2 ";
		}
	}
	return 0;
}
