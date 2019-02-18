/*
	Algorithm for Depth First Search in Graphs

*/

#include<bits/stdc++.h>
using namespace std;

class Graph{
	int v;
	
	list<int> *adj;
	void DFSUtil(int v, bool visited[]);	
	public:
		Graph(int v);
		
		void addEdge(int u,int v);
		
		void dfs(int s);
		
};

Graph::Graph(int v){
	this->v=v;
	adj=new list<int>[v];;
}

void Graph::addEdge(int u,int v){
	adj[u].push_back(v);
}

void Graph::DFSUtil(int v, bool visited[]) 
{ 
    visited[v] = true; 
    cout << v << " "; 
  
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
void Graph::dfs(int s) 
{ 
    bool *visited = new bool[v]; 
    for (int i = 0; i < v; i++) 
        visited[i] = false; 
  
    DFSUtil(s, visited); 
} 


int main(){
	Graph g(4);
	g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    
	g.dfs(1); 
	
	return 0;
}
