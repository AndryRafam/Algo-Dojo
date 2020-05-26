/* Eulerian Graph:
 * 1) Use kosaraju algorithm to check if the graph is strongly connected
 * 2) Compute the total degree of the graph
 
 If the graph is strongly connected and the total degree of the graph is equal the number of edges; the graph is Eulerian */

#include <bits/stdc++.h>
using namespace std;

#define N 300000

list<int> adj[N], gr[N];
vector<bool> visited;
vector<int> order,comps;

class Solution{
	public:
	static void dfs1(int s){
		visited[s]=true;
		for(auto u : adj[s]){
			if(!visited[u])
				dfs1(u);
		}
		order.emplace_back(s);
		return;
	}
	static void dfs2(int s){
		visited[s]=true;
		comps.emplace_back(s);
		for(auto w : gr[s]){
			if(!visited[w])
				dfs2(w);
		}
		return;
	}
	static void addEdge(int x, int y){
		adj[x].emplace_back(y);
		gr[y].emplace_back(x);
		return;
	}
	static int degree(int s){ // compute the degree of each vertex(nodes)
		int degree = 0;
		for(auto v = 0; v!=(int)adj[s].size(); v++)
			degree++;
		return degree;
	}
	static bool kosaraju(int nodes){
		visited.assign(nodes,false);
		for(auto i(1); i <= nodes; i++){
			if(!visited[i])
				dfs1(i);
		}
		visited.assign(nodes,false);
		int connect = 0;
		for(auto i(1); i <= nodes; i++){
			int s = order[nodes-i];
			if(!visited[s]){
				dfs2(s);
				connect++;
				comps.clear();
			}
		}
		return(connect==1 ? true:false);
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int nodes,edges,x,y;
	cin >> nodes >> edges;
	for(auto i = 1; i <= edges; i++){
		cin >> x >> y;
		Solution::addEdge(x,y);
	}
	int total_deg = 0;
	for(auto i = 1; i <= nodes; i++)
		total_deg+=Solution::degree(i);	
	cout << (Solution::kosaraju(nodes)==1 && total_deg==edges ? "Eulerian":"Not Eulerian") << endl;
	return 0;
}
