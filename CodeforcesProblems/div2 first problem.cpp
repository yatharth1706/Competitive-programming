#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

long long calc(string s,int n){
	int i=0;
	
	while(i<n && s[i]=='0') i++;
	long long ans=1;
	while(i<n){
		ans*=(s[i]-'0');
		i++;
	}
	return ans;
}
long long maxx=-1;
int main(){
	string s;
	cin>>s;
	int n=s.length();
	string t;
	maxx=calc(s,n);
	for(int i=0;i<n;i++){
		if(s[i]!=0){
			t=s;
			t[i]--;
			for(int j=i+1;j<n;j++){
				t[j]='9';
			}
			maxx=max(maxx,calc(t,n));
		}
	}
	cout<<maxx<<'\n';
}
