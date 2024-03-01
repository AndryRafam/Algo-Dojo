#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false)

int main() {
    fastio;
    cin.tie(0);
    string letters;
    int N; cin >> N >> letters;

    int size = 2*N-1;
    vector<vector<char>> grid(size,vector<char>(size));

    for(int i = 0; i < N; ++i) {
        char letter = letters[N-1-i];
        for(int j = i; j < size-i; ++j) {
            for(int k = i; k < size-i; ++k) {
                grid[j][k]=letter;
            }
        }
    }
    for(auto row : grid) {
        for(auto c : row) {
            cout << c;
        }
        cout << "\n";
    }
    return 0;
}