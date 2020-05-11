// Capital City

#include <bits/stdc++.h>
using namespace std;

#define N 300000

list<int> adj[N];
bool visited[N];

class Solution{
	public:
	static void dfs(int s){
		visited[s]=true;
		for(auto w : adj[s]){
			if(!visited[w])
				dfs(w);
		}
		return;
	}
	static void addEdge(int src, int dest){
		adj[src].emplace_back(dest); // directed graph
		return;
	}
	static void initialize(int nodes){
		for(auto i = 0; i < nodes; i++){
			visited[i]=false;
		}
		return;
	}
	static bool is_reachable(int src, int dest){
		int connect = 0;
		if(src <= dest){
			for(auto i = src; i <= dest; i++){
				if(!visited[i]){
					dfs(i);
					connect++;
				}
			}
		}
		else{
			for(auto i = src; i >= dest; i--){
				if(!visited[i]){
					dfs(i);
					connect++;
				}
			}
		}
		return(connect==1 ? true:false);
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	set<int> s;
	int nodes, edges, x, y;
	cin >> nodes >> edges;
	for(auto i = 1; i <= edges; i++){
		cin >> x >> y;
		Solution::addEdge(x,y);
	}

	for(auto i = 1; i <= nodes; i++){
		int count = 0;
		for(auto j = 1; j <= nodes; j++){
			Solution::initialize(nodes);
			if(Solution::is_reachable(j,i))
				count++;
		}
		if(count==nodes) // if i can be reached from any nodes; i is a candidate for capital city
			s.insert(i);
	}
	cout << s.size() << "\n";
	for(auto x : s)
		cout << x << " ";
	cout << "\n";
}
