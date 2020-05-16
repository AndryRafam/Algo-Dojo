// Kosaraju Algorithm (Strongly Connected Components)

#include <bits/stdc++.h>
using namespace std;

#define N 300000

vector<int> adj[N],gr[N];
vector<bool> visited;
/* Order of the nodes according to the structure of the graph
   Strongly connected components */
vector<int> order,comps;

class Solution{
    public:
    // Constructs a list of nodes according to the structure of the graph
    static void dfs1(int s){ 
        visited[s]=true;
        for(auto u : adj[s]){
            if(!visited[u])
                dfs1(u);
        }
        order.emplace_back(s);
        return;
    }
    // Second dfs which forms the strongly connected components
    static void dfs2(int s){
        visited[s]=true;
        comps.emplace_back(s);
        for(auto u : gr[s]){
            if(!visited[u])
                dfs2(u);
        }
        return;
    }
    static void addEdge(int x, int y){
        adj[x].emplace_back(y);
        gr[y].emplace_back(x);
        return;
    }
    static void kosaraju(int nodes){
        visited.assign(nodes,false);
        for(auto i = 1; i <= nodes; i++){
            if(!visited[i])
                dfs1(i);
        }
        visited.assign(nodes,false);
        int count = 0;
        for(auto i = 1; i <= nodes; i++){
            int s = order[nodes-i];
            if(!visited[s]){
                dfs2(s);
                for(auto j : comps)
                    cout << j << " ";
                cout << endl;
                count++;
                comps.clear();
            }
        }
        cout << "Number of connected component -> " << count << endl;
        return;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int nodes, edges, x, y;
    cin >> nodes >> edges;
    for(auto i = 1; i <= edges; i++){
        cin >> x >> y;
        Solution::addEdge(x,y);
    }
    Solution::kosaraju(nodes);
    return 0;
}
