// Find cycle in directed graph

#include <bits/stdc++.h>
using namespace std;

#define N 300000

list<int> adj[N];
bool visited[N];
bool flag[N];

class Solution{
	public:
	static void dfs_cycle(int s){
		visited[s]=true;
		flag[s]=true;
		for(auto u : adj[s]){
			if(!visited[u]&&!flag[u])
				dfs_cycle(u);
			else if(flag[u]==true){
				cout << u << " ";
			}
		}
		return;
	}
	static void addEdge(int x, int y){
		//directed graph
		adj[x].emplace_back(y);
		return;
	}
	static void initialize(){
		for(auto i = 0; i < N; i++){
			visited[i]=false;
			flag[i]=false;
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
	
	cout << "\n";
	for(auto i = 1; i <= nodes; i++){
		if(!visited[i]){
			Solution::dfs_cycle(i);
		}
	}
	return 0;
}
