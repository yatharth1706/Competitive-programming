/*
	Problem name : Multiplicity
	Problem tutorial : https://codeforces.com/problemset/problem/1061/C

*/


#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
const int modd=1e9+7;
int countt[maxn];
int arr[maxn];
typedef long long int ll;
# define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
int main(){
	boost;
	int n;
	cin>>n;
	
	int i,j;
	countt[0]=1;
	for(i=1;i<=n;i++){
		cin>>arr[i];
		vector<int> v; // for storing divisors of every array number
		for(j=1;j*j<=arr[i];j++){
			if(arr[i]%j==0){
				v.push_back(j);
				if(j!=arr[i]/j){
					v.push_back(arr[i]/j);
				}
			}
		}
		sort(v.rbegin(),v.rend());
		for(auto &it :v){
			countt[it]+=countt[it-1];
			countt[it]%=modd;
		}
		
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=countt[i];
	}
	ans%=modd;
	cout<<ans<<'\n';
	
	return 0;
}
