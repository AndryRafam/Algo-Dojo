#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int Na; cin >> Na;
    for(int i = 0; i < Na; ++i) {
        int x;
        cin >> x;
        minHeap.push(x);
    }
    int Nb; cin >> Nb;
    for(int j = 0; j < Nb; ++j) {
        int y;
        cin >> y;
        minHeap.push(y);
    }
    while(!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    return 0;
}

