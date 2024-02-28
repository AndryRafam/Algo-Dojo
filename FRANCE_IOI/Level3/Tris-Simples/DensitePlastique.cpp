/*France IOI - Niveau 3.
Tris Simples: Densité Plastique.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    set<int> stock;
    int N; cin >> N;
    for(int i = 0; i < N; ++i) {
        int dens; cin >> dens;
        stock.insert(dens);
    }
    int Q; cin >> Q;
    for(int j = 0; j < Q; ++j) {
        int qdens; cin >> qdens;
        if(stock.find(qdens)!=stock.end()) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    return 0;
}