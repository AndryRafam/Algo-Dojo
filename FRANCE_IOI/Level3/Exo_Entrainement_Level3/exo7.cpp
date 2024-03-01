#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    vector<int> tableau(N);
    for(int i = 0; i < N; ++i) {
        cin >> tableau[i];
    }
    int count = 0;
    unordered_set<int> st(tableau.begin(),tableau.end());
    for(int x : st) {
        if(x > 0 && st.find(0-x)!=st.end()) {
            count++;
        }
    }
    cout << count;
    return 0;
}