#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    int client[N];
    unordered_set<int> tricheur;
    for(int i = 0; i < N; ++i) {
        cin >> client[i];
        if(tricheur.find(client[i])!=tricheur.end()) {
            cout << client[i];
            return 0;
        }
        tricheur.insert(client[i]);
    }
    cout << -1;
    return 0;
}