/*

Problem link: https://codeforces.com/problemset/problem/467/B
Problem name: Fedor and New Game

*/

#include<bits/stdc++.h>
using namespace std;
# define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;

int countBits(int a,int b){
	int count=0;
	for(int i=0;i<32;i++){
		if(((a>>i)&1)!= ((b>>i)&1)){
			count++;
		}	
	}
	return count;
}
const int maxn=10002;
int arr[maxn];
int main(){
	boost;
	int n,m,k;
	cin>>n>>m>>k;
	
	for(int i=0;i<m+1;i++){
		cin>>arr[i];
	}
	int c=0;
	for(int i=0;i<m;i++){
		int v=countBits(arr[i],arr[m]);
		if(v<=k){
			c++;
		}
	}
	cout<<c<<'\n';
	
	return 0;
}

