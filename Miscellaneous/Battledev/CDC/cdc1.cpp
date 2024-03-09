#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int solde; cin >> solde;
    vector<int> digits;
    while(solde > 0) {
        digits.emplace_back(solde%10);
        solde/=10;
    }
    sort(digits.begin(),digits.end());
    for(int i = 0; i < (int)digits.size(); ++i) {
        if(digits[0]==0) {
            swap(digits[0],digits[1]);
        }
        cout << digits[i];
    }
    cout << "\n";
    for(int j = (int)digits.size()-1; j >= 0; --j) {
        cout << digits[j];
    }
    return 0;
}