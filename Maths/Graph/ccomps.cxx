// Connected components of directed graph

#include <bits/stdc++.h>
using namespace std;

#define N 300000

list<int> adj[N];
vector<bool> visited;
vector<int> comps;

class Solution{
    public:
    static void dfs(int s){
        visited[s]=true;
        comps.emplace_back(s);
        for(auto u : adj[s]){
            if(!visited[u])
                dfs(u);
        }
        return;
    }
    static void addEdge(int x, int y){
        //directed graph
        adj[x].emplace_back(y);
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
    visited.assign(nodes,false);

    int count = 0; // count connected component
    cout << endl;
    for(auto i = 1; i <= nodes; i++){
        if(!visited[i]){
            comps.clear();
            Solution::dfs(i);
            for(auto j : comps)
                cout << j << " ";
            cout << endl;
            count++;
        }
    }
    cout << "Connected component -> " <<  count << endl;
    return 0;
}