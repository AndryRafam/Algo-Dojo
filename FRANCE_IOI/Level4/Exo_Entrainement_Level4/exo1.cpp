#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int count = 0;
    int L,C; cin >> L >> C;
    vector<vector<char>> labyrinthe(L,vector<char>(C));
    for(int l = 0; l < L; ++l) {
        for(int c = 0; c < C; ++c) {
            cin >> labyrinthe[l][c];
            if(labyrinthe[l][c]=='#') {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}