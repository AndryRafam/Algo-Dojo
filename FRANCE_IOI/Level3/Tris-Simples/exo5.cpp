/*France IOI - Niveau 3.
Tris Simples: Identifier les bacs.
*/

#include <bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        if(a.first==b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> minHeap;
    int nbBacs; cin >> nbBacs;
    int idBac,nivPoll;
    for(int i = 0; i < nbBacs; ++i) {
        cin >> idBac >> nivPoll;
        minHeap.push({nivPoll,idBac});
    }
    while(!minHeap.empty()) {
        cout << minHeap.top().second << " " << minHeap.top().first << "\n";
        minHeap.pop();
    }
    return 0;
}