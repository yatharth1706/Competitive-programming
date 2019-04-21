#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//int main(){
//	boost;
//	int t;
//	cin>>t;
//	while(t--){
//		int n,k;
//		cin>>n>>k;
//		int arr[n];
//		ll sum=0;
//		ll temp;
//		for(int i=0;i<n;i++){
//			cin>>arr[i];
////			sum+=arr[i];
//		}
//		ll maxx=-1e9;
//		int j=0;
//		for(int pos=0;pos<n;pos++){
//			sum=0;
//			j=pos;
//			while(j<n){
//				sum+=arr[j];
//				j+=k;
//			}
//			maxx=max(maxx,sum);
//		}
//		cout<<maxx<<'\n';
//	}
//	return 0;
//}
const int maxn=1e5;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int arr[n];
		ll countt[n];
		memset(countt,0,sizeof(countt));
		for(int i=0;i<n;i++){
			cin>>arr[i];
			countt[i%k]+=arr[i];
		}
		for(int i=k;i<n;i++){
			countt[i]=countt[i-k]-arr[i-k];
		}
		ll maxx=countt[0];
		for(int i=1;i<n;i++){
			maxx=max(maxx,countt[i]);
		}
		
		cout<<maxx<<'\n';
	}
	return 0;
}
