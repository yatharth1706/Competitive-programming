/*

-------------Algorithm for Breadth First Traversal in a Graph--------------------------------

*/
#include<bits/stdc++.h>
using namespace std;

class Graph{
	int v;
	
	list<int> *adj;
	
	public:
	
	Graph(int v);
	
	void addEdge(int u,int v);
	
	void bfs(int s);
};

Graph::Graph(int v){
	this->v=v;
	adj=new list<int>[v];
}

void Graph::addEdge(int u,int v){
	adj[u].push_back(v);
}

void Graph::bfs(int s){
	bool *visited=new bool[v];
	for(int i=0;i<v;i++){
		visited[i]=false;
	}
	
	visited[s]=true;
	list<int> queue;
	
	queue.push_back(s);
	
	while(!queue.empty()){
		s=queue.front();
		cout<<s<<" ";
		queue.pop_front();
		
		for(auto it=adj[s].begin();it!=adj[s].end();it++){
			if(!visited[*it]){
				visited[*it]=true;
				queue.push_back(*it);
			}
			
		}
	}
}

int main(){
	Graph g(4);
	
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);
	
	cout<<"BFS for this graph is as : "<<'\n';
	g.bfs(2);
	
	return 0;
}
