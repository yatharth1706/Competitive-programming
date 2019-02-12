/* Problem Name: Yet Another Array Partitioning Task
	
	Problem link: https://codeforces.com/contest/1114/problem/B

*/


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn=2e5+12;
bool has[maxn+3];
int main(){
	ll n,m,k;
	cin>>n>>m>>k;
	ll arr[n+1],brr[n+1];
	
	for(ll i=1;i<=n;i++){
		cin>>arr[i];
		brr[i]=i;
	}
	
	ll c1,c2;
	c1=c2=0;
	ll sum=0;
	
	sort(brr+1,brr+n+1,[&](ll i,ll j){return arr[i] > arr[j];});
	for(ll i=1;i<=(m*k);i++){
		sum+=arr[brr[i]];
		has[brr[i]]=true;
	}
	
	cout<<sum<<'\n';
	ll count=0;
	vector<ll> ans;
	for(ll i=1;i<=n;i++){
		if(has[i]){
			count++;
			if(count==m){
				ans.push_back(i);
				count=0;
			}
		}
	}
	for(ll i=0;i<k-1;i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	
	return 0;
}
