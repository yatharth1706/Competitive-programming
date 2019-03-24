/*
	problem name: Kefa and Park
	problem link: https://codeforces.com/contest/580/problem/C

*/
#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long int ll;
vector<vector<int>> adj;
const int maxn=2e5+5;
// task yet to complete
// have to make a dfs in a such a way that we only go to leaf nodes if in a path there are not consecutive k cats.
bool visited[maxn];
int cat[maxn];
int res;
int m;
// most important part of whole solution
void dfs(int pos,int countt){
	visited[pos]=true;
	if(countt>m){
		return;
	}
	bool isLeaf=1;
	
	for(auto it=adj[pos].begin();it!=adj[pos].end();it++){
		if(!visited[*it]){
			isLeaf=0;
			if(cat[*it]) dfs(*it,countt+1);
			else dfs(*it,0);
		}
	}	
	if(isLeaf){
		res+=1;
	}
}

int main(){
	boost;
	int n;
	cin>>n>>m;
	adj= vector<vector<int>>(maxn);
	
	for(int i=1;i<=n;i++){
		cin>>cat[i];			
	}
	
	for(int i=0;i+1<n;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	dfs(1,cat[1]);
	cout<<res<<'\n';
	return 0;
}
