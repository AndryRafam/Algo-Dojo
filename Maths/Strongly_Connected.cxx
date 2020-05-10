/* Strongly Connected graph using BFS */

#include <bits/stdc++.h>
using namespace std;

#define N 300000

list<int> adj[N];
queue<int> q;
bool visited[N];

class Solution{
	public:
	static void BFS(int s){
		visited[s]=true;
		q.push(s);
		while(!q.empty()){
			int x = q.front();
			q.pop();
			for(auto u : adj[x]){
				if(visited[u])
					continue;
				visited[u]=true;
				q.push(u);
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
		for(auto i = 0; i < N; i++)
			visited[i]=false;
		return;
	}
	static bool check(int src, int dest){
		int connected = 0;
		if(src <= dest){
			for(auto i = src; i <= dest; i++){
				if(!visited[i]){
					BFS(i);
					connected++;
				}
			}
		}
		else if(src > dest){
			for(auto i = src; i >= dest; i--){
				if(!visited[i]){
					BFS(i);
					connected++;
				}
			}
		}
		return(connected==1 ? true:false);
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	int nodes, edges, x, y;
	cout << "Nodes, Edges -> ";
	cin >> nodes >> edges;
	for(auto i = 1; i <= edges; i++){
		cin >> x >> y;
		Solution::addEdge(x,y);
	}

	Solution::initialize();

	for(auto i = 1; i <= nodes; i++){
		for(auto j = 1; j <= nodes; j++){
			Solution::initialize(); // In each round, make all nodes not visited
			if(!Solution::check(i,j)){
				cout << "NOT STRONGLY CONNECTED\n";
				return 0;
			}
		}
	}
	cout << "STRONGLY CONNECTED\n";
	return 0;
}
