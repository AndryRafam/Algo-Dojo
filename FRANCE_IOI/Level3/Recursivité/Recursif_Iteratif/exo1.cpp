#include <bits/stdc++.h>
using namespace std;

void printNumbers(int N, int M) {
    if(N <= M) {
        cout << N << " ";
        printNumbers(N+1,M);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,M; cin >> N >> M;
    printNumbers(N,M);
    return 0;
}