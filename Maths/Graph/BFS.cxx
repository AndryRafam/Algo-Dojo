/* BFS: Breadth first search algorithm
 * 
 * Consider the following undirected graph: 1--2--3--6--5--2 && 1--4 */

#include <bits/stdc++.h>
using namespace std;

#define N 300000

list<int> adj[N];
queue<int> q;
bool visited[N];

class Solution{
	public:
	static void BFS(int x){
		visited[x]=true;
		q.push(x);
		while(!q.empty()){
			int s = q.front(); q.pop();
			for(auto u : adj[s]){
				if(visited[u])
					continue;
				visited[u]=true;
				q.push(u);
			}
		}
		return;
	}
	static void addEdge(int x, int y){
		// undirected graph
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
		return;
	}
	static void initialize(){
		for(auto i = 0; i < N; i++)
			visited[i]=false;
		return;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	int nodes, edges, x, y, connected_parts = 0;
	cin >> nodes >> edges;
	for(auto i = 1; i <= edges; i++){
		cin >> x >> y;
		Solution::addEdge(x,y);
	}
	
	Solution::initialize();
	
	for(auto i = 1; i <= nodes; i++){
		if(!visited[i]){
			Solution::BFS(i);
			connected_parts++;
		}
	}
	cout << "\n";
	cout << (connected_parts==1 ? "Connected":"Not Connected");
	return 0;
}
