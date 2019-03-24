/*
	Problem name: Spanning Tree with Maximum Degree
	Problem link: https://codeforces.com/contest/1133/problem/F1

*/
#include<bits/stdc++.h>
using namespace std;

// bfs for graph
const int maxn=2e5+10;
vector<pair<int,int>> ans;
vector<vector<int>> adj;
void bfs(int pos,int n){
	bool visited[n];
	memset(visited,false,sizeof(visited));
	
	list<int> q;
	visited[pos]=true;
	q.push_back(pos);
	while(!q.empty()){
		int s=q.front();
		q.pop_front();
		for(auto it = adj[s].begin();it!=adj[s].end();it++){
			if(!visited[*it]){
				visited[*it]=true;
				q.push_back(*it);
				ans.push_back(make_pair(s,*it));
			}
		}
	}
	
}
int main(){

	int n,m;
	cin>>n>>m;
	adj=vector<vector<int>>(n);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--;y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int maxx=0;
	int pos=0;
	// for finding the maximum degree vertex
	for(int i=0;i<n;i++){
		if(adj[i].size()>maxx){
			maxx=adj[i].size();
			pos=i;
		}
	}
	bfs(pos,n);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first+1<<" "<<ans[i].second+1<<'\n';
	}
	return 0;
}
