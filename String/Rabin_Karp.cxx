/* Rabin-Karp algorithm for string matching

O(|s|+|t|) time complexity, where s is a pattern and t is a text */

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static vector<int> RK(string const &s, string const &t){
        const int p = 53;
        const int mod = 1e9 + 7;
        int m = s.size(), n = t.size();

        vector<long long> p_pow(max(m,n));
        p_pow[0]=1;
        for(auto i = 1; i < (int)p_pow.size(); i++)
            p_pow[i]=(p_pow[i-1]*p)%mod;
        
        vector<long long> h(n+1,0);
        for(auto i = 0; i < n; i++)
            h[i+1] = (h[i]+(t[i]-'a'+1)*p_pow[i])%mod;
        long long h_s = 0;
        for(auto i = 0; i < m; i++)
            h_s = (h_s+(s[i]-'a'+1)*p_pow[i])%mod;
        
        vector<int> occur;
        for(auto i = 0; i+m-1 < n; i++){
            long long cur_h = (h[i+m]+mod-h[i])%mod;
            if(cur_h == h_s*p_pow[i]%mod)
                occur.emplace_back(i);
        }
        return occur;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string const &s = "geko";
    string const &t = "gekoisgekoman";
    for(auto &x : Solution::RK(s,t))
        cout << x << " ";
    cout << endl;
    return 0;
}
