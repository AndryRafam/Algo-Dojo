// Bipartiteness directed graph

#include <bits/stdc++.h>
using namespace std;

#define N 300000

list<int> adj[N];
bool visited[N];
bool color[N]; // blue or red
bool bipartite = true;

class Solution{
	public:
	static bool dfs_bip(int s){
		visited[s]=true;
		color[s]=true; // blue
		for(auto u : adj[s]){
			if(!visited[u]&&!color[u])
				dfs_bip(u);
			else if(color[u]==true){ // if adj[s][nodes] is same color as s, bipartiteness is false
				bipartite=false;
				return bipartite;
			}
		}
		bipartite = true;
		return bipartite;
	}
	static void addEdge(int x, int y){
		//directed graph
		adj[x].emplace_back(y);
		return;
	}
	static void initialize(){
		for(auto i = 0; i < N; i++){
			color[i]=false;
			visited[i]=false;
		}
		return;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	int nodes, edges, x, y;
	cin >> nodes >> edges;
	for(auto i = 1; i <= edges; i++){
		cin >> x >> y;
		Solution::addEdge(x,y);
	}
	
	Solution::initialize();
	
	for(auto i = 1; i <= nodes; i++){
		if(!visited[i]){
			if(Solution::dfs_bip(i)==false){
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}
