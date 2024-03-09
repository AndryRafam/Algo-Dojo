#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

vector<int> dijkstra(vector<vector<pii>>& graph, int source) {
    int n = graph.size();
    vector<int> distance(n,INT_MAX);
    priority_queue<pii,vector<pii>,greater<pii>> pq;

    distance[source] = 0;
    pq.push({0,source});

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for(auto &neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if(distance[u]+weight < distance[v]) {
                distance[v]=distance[u]+weight;
                pq.push({distance[v],v});
            }
        }
    }
    return distance;
}

int main() {
    ios::sync_with_stdio(false);
    vector<vector<pii>> graph = {
        {{1,10},{2,4}},
        {{0,10}},
        {{0,4},{3,6},{4,3}},
        {{2,6},{4,10}},
        {{2,3},{3,10}}
    };
    vector<int> distanceA = dijkstra(graph,0);
    vector<int> distanceB = dijkstra(graph,4);

    for(int i = 1; i <= 3; ++i) {
        cout << "Server " << i << ": " << distanceA[i]+distanceB[i] << "\n";
    }
    return 0;
}