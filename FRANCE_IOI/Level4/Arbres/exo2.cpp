#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> contains;
vector<int> maxSteps;

int findMaxSteps(int R) {
    if (maxSteps[R] != -1) {
        return maxSteps[R];
    }
    int steps = 0;
    for (int obj : contains[R]) {
        steps = max(steps, 1 + findMaxSteps(obj));
    }
    maxSteps[R] = steps;
    return steps;
}

int main() {
    int N;
    cin >> N;
    vector<int> positions(N+1);
    contains.resize(N+1);
    maxSteps.resize(N+1, -1);
    for (int i = 1; i <= N; i++) {
        cin >> positions[i];
        contains[positions[i]].push_back(i);
    }
    cout << findMaxSteps(0) << "\n";
    return 0;
}
