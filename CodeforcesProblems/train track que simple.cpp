#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,s;
	cin>>n>>s;
	int track1[n];
	int track2[n];
	for(int i=0;i<n;i++){
		cin>>track1[i];
	}
	for(int i=0;i<n;i++){
		cin>>track2[i];
	}
	
	int maxx=0;
	if(track1[0]==0){
		cout<<"NO"<<'\n';
	}
	
	else if(track1[s-1]!=1){
		for(int i=0;i<n;i++){
			if(track1[i] && track2[i]){
				maxx=i;
			}
		}
		if(track2[s-1]&& maxx>=s){
			cout<<"YES"<<'\n';
		}
		else{
			cout<<"NO"<<'\n';
		}
	}
	else if(track1[0]==1 && track1[s-1]==1){
		cout<<"YES"<<'\n';
	}
}
