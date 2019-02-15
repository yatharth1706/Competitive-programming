#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n,s,k,m,M;
		cin>>n>>s>>k>>m>>M;
		
		ll arr[n];
		ll sum=0;
		for(int i=0;i<n-1;i++){
			arr[i]=1;
			sum+=arr[i];
		}
		arr[n-1]=(s-sum);
		if(arr[n-1]>M){
			sum=0;
			arr[n-1]=M;
			for(ll i=0;i<n-2;i++){
				arr[i]=1;
				sum+=arr[i];
			}
			sum+=arr[n-1];
			
			arr[n-2]=(s-sum);
		}
		
		vector<ll> v;
		for(ll i=0;i<n;i++){
			if(i==k || i==n%k){
				continue;
			}
			else{
				v.push_back(arr[i]);
			}
		}
		ll median=v[(n-2)/2];
		ll med2=arr[n/2];
		if(median!=med2){
			for(ll i=0;i<n;i++){
				cout<<arr[i]<<' ';
			}
			cout<<'\n';
		}
		else{
			cout<<-1<<'\n';
		}
		
	}
	return 0;
}
