/*

	Algorithm: Finding the mother vertex in the graph(Mother vertex is the vertex from which we can visit all the nodes in the directed graph)	
	
	The key idea here is the last finished vertex in DFS algorithm will be always the one of the mother vertex in a graph if it exists. 
*/

#include<bits/stdc++.h>
using namespace std;

class Graph{
	int v;
	
	list<int> *adj;
	void DFSUtil(int v,vector<bool> &visited);	
	public:
		Graph(int v);
		int findMother();
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

void Graph::DFSUtil(int v, vector<bool> &visited) 
{ 
    visited[v] = true; 
  
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  


int Graph::findMother() 
{ 
    vector <bool> visited(v, false); 
  
    int x = 0; 
  
    for (int i = 0; i < v; i++) 
    { 
        if (visited[i] == false) 
        { 
            DFSUtil(i, visited); 
            x = i; 
        } 
    } 
  
    fill(visited.begin(), visited.end(), false); 
    DFSUtil(x, visited);  
    for (int i=0; i<v; i++) 
        if (visited[i] == false) 
            return -1; 
  
    return x; 
}

int main(){
	Graph g(7); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(4, 1); 
    g.addEdge(6, 4); 
    g.addEdge(5, 6); 
    g.addEdge(5, 2); 
    g.addEdge(6, 0); 
  
    cout << "Mother vertex"<<" "<<g.findMother(); 
    
	
	
	return 0;
}
