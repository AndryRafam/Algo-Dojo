/*France IOI - Niveau 3.
Tris Simples: Matière recyclable.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<string,vector<string>,greater<string>> minHeap;
    int N; cin >> N;
    for(int i = 0; i < N; ++i) {
        string word;
        cin >> word;
        minHeap.push(word);
    }
    while(!minHeap.empty()) {
        cout << minHeap.top() << "\n";
        minHeap.pop();
    }
    return 0;
}