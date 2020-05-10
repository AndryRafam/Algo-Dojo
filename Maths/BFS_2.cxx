/* Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a route between two nodes.
 * 
 * Consider the following directed graph as an example: 1->2->3->6->5->2 && 1->4.
 *  
 * As we see, for example, starting from the 1st node, we can reach every nodes; but, starting from 6th nodes, we can't reach
 * 
 * the 4th node (6 and 4 are disconnected). 
 * 
 * We are going to use BFS in order to prove it. */

#include <bits/stdc++.h>
using namespace std;

#define N 300000

vector<int> adj[N];
queue<int> q;
bool visited[N];

class Solution{
	public:
	static void BFS(int x){
		visited[x]=true;
		q.push(x);
		while(!q.empty()){
			int s = q.front(); q.pop();
			for(auto  u : adj[s]){
				if(visited[u])
					continue;
				visited[u]=true;
				q.push(u);
			}
		}
		return;
	}
	static void addEdge(int x, int y){
		// directed graph
		adj[x].emplace_back(y);
		return;
	}
	static void initialize(){
		for(auto i = 0; i < N; i++){
			visited[i]=false;
		}
		return;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	int edges, x, y, way = 0;
	cout << "Edges-> ";
	cin >> edges;
	for(auto i = 1; i <= edges; i++){
		cin >> x >> y;
		Solution::addEdge(x,y);
	}
	
	Solution::initialize();
	
	cout << "\nEnter src and dest: ";
	int src, dest;
	cin >> src >> dest;
	
	if(src <= dest){
		for(auto i = src; i <= dest; i++){
			if(!visited[i]){
				Solution::BFS(i);
				way++;
			}
		}
	}
	else{
		for(auto i = src; i >= dest; i--){
			if(!visited[i]){
				Solution::BFS(i);
				way++;
			}
		}
	}
	cout << (way==1 ? "Reachable":"Not Reachable"); // If way is more than 1; this means that the graph is disconnected
	return 0;
}
