#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> pq;
    int N; cin >> N;
    for(int i = 0; i < N; ++i) {
        string fournisseur; cin >> fournisseur;
        cin.ignore();
        int carbone; cin >> carbone;
        pq.push({carbone,fournisseur});
    }
    cout << "\n" << pq.top().second;
    return 0;
}