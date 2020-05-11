/* Connectivity check: DFS (Depth first search algorithm)
 * 
 * Given an undirected graph, check if it is a connected graph.
 * 
 * As an example, lets take a look of this graph: 1--2--3--1 4--5 6; which has 4 edges and 6 nodes */ 


#include <bits/stdc++.h>
using namespace std;

#define N 300000

list<int> adj[N];
bool visited[N];

class Solution{
	public:
	static void dfs(int s){ // recursive dfs
		visited[s]=true;
		for(auto w : adj[s]){
			if(!visited[w]){
				dfs(w);
			}
		}
		return;
	}
	static void initialize(){
		for(auto i = 0; i < N; i++){
			visited[i]=false;
		}
	}
	static void addEdge(int src, int dest){
		// undirected graph
		adj[src].emplace_back(dest);
		adj[dest].emplace_back(src);
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int nodes, edges, x, y, connected_parts = 0;
	cin >> nodes >> edges; // 6 4
	for(auto i = 1; i <= edges; i++){
		cin >> x >> y;
		Solution::addEdge(x,y); // create the graph 
	}
	
	Solution::initialize(); // Initialize all nodes as not visited
	
	for(auto i = 1; i <= nodes; i++){
		if(!visited[i]){
			Solution::dfs(i);
			connected_parts++;
		}
	}
	cout << "\n";
	cout << (connected_parts==1 ? "CONNECTED":"NOT CONNECTED");
	return 0;
}
