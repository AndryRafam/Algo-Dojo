// https://cses.fi/problemset/task/1731

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main(){
    string s; cin >> s;
    int k; cin >> k;
    vector<string> words(k);
    for(auto i(0); i < k; ++i){
        cin >> words[i];
    }
    int n = s.length();
    vector<int> dp(n+1,0);
    dp[0] = 1;

    for(auto i(1); i <= n; ++i){
        for(const string word : words){
            int len = word.length();
            if(i >= len && s.substr(i-len,len)==word){
                dp[i] = (dp[i]+dp[i-len])%MOD;
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}