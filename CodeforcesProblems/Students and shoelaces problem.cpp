/*
Problem link :https://codeforces.com/contest/129/problem/B

Problem Name: Students and shoelaces problem

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
# define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

set<int> yv[200];
vector<int> v;
# define pb(x) push_back(x);
int vis[200];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		yv[x].insert(y);
		yv[y].insert(x);		
	}
	bool flag;
	int ans=0;
	
	while(1){
		flag=0;
		v.clear();
		for(int i=1;i<=n;i++){
			if(vis[i]==0 && yv[i].size()==1){
				v.pb(i);
				flag=1;
				vis[i]=1;
			}
		}
		if(!flag){
			break;
		}
		else{
			ans++;
			for(int i: v){
				for(int j: yv[i]){
					yv[j].erase(i);
				}
			}
		}
	}
	cout<<ans<<'\n';	
	return 0;
}
