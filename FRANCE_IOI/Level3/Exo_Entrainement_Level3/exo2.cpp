#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int P; cin >> P;
    vector<int> arrP(P);
    for(int i = 0; i < (int)arrP.size(); ++i) {
        cin >> arrP[i];
    }
    int S; cin >> S;
    vector<int> arrS(S);
    for(int j = 0; j < (int)arrS.size(); ++j) {
        cin >> arrS[j];
    }
    sort(arrP.begin(),arrP.end());
    sort(arrS.begin(),arrS.end());
    int count_intersect = 0;
    for(auto v : arrP) {
        if(binary_search(arrS.begin(),arrS.end(),v)) {
            count_intersect++;
        }
    }
    cout << count_intersect;
    return 0;
}