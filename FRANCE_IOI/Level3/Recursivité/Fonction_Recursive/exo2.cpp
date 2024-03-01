#include <bits/stdc++.h>
using namespace std;

string zero(int n) {
    if(n==0) {
        return "0";
    } else {
        return "("+zero(n-1)+" + "+zero(n-1)+")";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    cout << "0 = " << zero(N);
    return 0;
}