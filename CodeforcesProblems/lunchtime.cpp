#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		ll x;
		cin>>n>>x;
		string di;
		set<ll> s;
		cin>>di;
		s.insert(x);
		ll c=x;
		for(int i=0;i<di.length();i++){
			if(di[i]=='L'){
				c-=1;
				s.insert(c);
			}
			else{
				c+=1;
				s.insert(c);
			}
		}
		cout<<s.size()<<'\n';
	}
	
}
