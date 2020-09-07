/* Sum of product of pairs */
#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000007

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long sum = 0;
    long long t, N; cin >> N;
    cin.ignore();
    vector<long long> integer;
    for(auto i = 0; i < N; i++){
        cin >> t;
        cin.ignore();
        integer.emplace_back(t);
    }
    for(auto i = 0; i < N-1; i++){
        for(auto j = i+1; j < N; j++){
            sum+=(integer[i]%MAX)*(integer[j]%MAX);
        }
    }
    cout << sum%MAX << endl;
    return 0;
}