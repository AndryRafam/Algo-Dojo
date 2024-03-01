#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, N;
    cin >> K >> N;
    vector<int> current(N);
    for (int i = 0; i < N; i++) {
        cin >> current[i];
    }
    int max_sum = 0;
    int current_sum = 0;
    for (int i = 0; i < K; i++) {
        current_sum += current[i];
    }
    max_sum = current_sum;
    for (int i = K; i < N; i++) {
        current_sum = current_sum - current[i - K] + current[i];
        max_sum = max(max_sum, current_sum);
    }
    cout << max_sum << endl;
    return 0;
}
