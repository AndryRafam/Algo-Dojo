#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> pollution(N);
    for(int i = 0; i < N; i++) {
        cin >> pollution[i];
    }
    for(int i = 0; i < M; i++) {
        int P;
        cin >> P;
        int pos = lower_bound(pollution.begin(), pollution.end(), P) - pollution.begin();
        pollution.insert(pollution.begin() + pos, P);
        cout << pos << " ";
    }
    cout << endl;
    for(int i = 0; i < (int)pollution.size(); i++) {
        cout << pollution[i] << " ";
    }
    return 0;
}
