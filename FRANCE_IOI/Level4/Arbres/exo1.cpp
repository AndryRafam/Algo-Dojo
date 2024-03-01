#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> findPositions(int N, vector<int>& positions, vector<int>& queries) {
    vector<vector<int>> result;
    for (int query : queries) {
        vector<int> path;
        int current = query;
        while (current != 0) {
            path.push_back(current);
            current = positions[current - 1];
        }
        result.push_back(path);
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    vector<int> positions(N);
    for (int i = 0; i < N; i++) {
        cin >> positions[i];
    }
    int R;
    cin >> R;
    vector<int> queries(R);
    for (int i = 0; i < R; i++) {
        cin >> queries[i];
    }
    vector<vector<int>> result = findPositions(N, positions, queries);
    for (const auto& path : result) {
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
