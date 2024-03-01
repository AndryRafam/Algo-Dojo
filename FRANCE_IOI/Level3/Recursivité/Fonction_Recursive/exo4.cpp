#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        cout << from << " -> " << to << "\n";
    } else {
        hanoi(n - 1, from, aux, to);
        cout << from << " -> " << to << "\n";
        hanoi(n - 1, aux, to, from);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    hanoi(N, 1, 3, 2);

    return 0;
}
