#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> marker;

int findParent(int R) {
    while (parent[R] != R) {
        R = parent[R];
    }
    return R;
}

int main() {
    int N;
    cin >> N;
    parent.resize(N+1);
    marker.resize(N+1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> parent[i];
    }
    int R;
    cin >> R;
    for (int i = 0; i < R; i++) {
        int obj1, obj2;
        cin >> obj1 >> obj2;
        int temp = obj1;
        while (temp != 0) {
            marker[temp] = i+1;
            temp = parent[temp];
        }
        temp = obj2;
        while (temp != 0 && marker[temp] != i+1) {
            temp = parent[temp];
        }
        cout << temp << "\n";
    }
    return 0;
}
