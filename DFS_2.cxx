/* Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a route between two nodes.
 * 
 * Consider the following directed graph as an example: 1->2->3->4->1 && 4->5.
 * 
 * As we see, from example, the 5th node is reachable starting from any nodes; but no nodes are reachable starting from 5.
 * 
 * In fact, the directed graph 4->5 is here disconnected to the directed graph 1->2->3->4->1.
 * 
 * We are going to use DFS in order to prove this statement. */
 
 
#include <bits/stdc++.h>
using namespace std;

#define N 300000 // 300000 so we can have enough space
 
vector<int> adj[N]; 
bool visited[N];
 
class Solution{
	public:
	static void DFS(int s){ // recursive dfs
		visited[s]=true;
		for(auto w : adj[s]){
			if(!visited[w])
				DFS(w);
		}
		return;
	}
	static void initialize(){
		for(auto i = 0; i < N; i++)
			visited[i]=false;
		return;
	}
	static void addEdge(int src, int dest){ // directed graph
		adj[src].emplace_back(dest);
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
	
	int src, dest;
	
	cout << "\nEnter the src and dest: ";
	cin >> src >> dest;
	if(src <= dest){
		for(auto i = src; i <= dest; i++){
			if(!visited[i]){
				Solution::DFS(i);
				way++;
			}
		}
	}
	else{
		for(auto i = src; i >= dest; i--){
			if(!visited[i]){
				Solution::DFS(i);
				way++;
			}
		}
	} 
	cout << (way==1 ? "Reachable\n":"Not Reachable\n"); // If way is more than 1; this means that the graph is disconnected
	return 0;
}
