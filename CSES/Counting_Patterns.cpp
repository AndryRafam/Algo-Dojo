//https://cses.fi/problemset/task/2103

#include <bits/stdc++.h>
using namespace std;

int countPatterns(string s, string p){
    int count = 0;
    vector<int> hashS(26,0);
    vector<int> hashP(26,0);

    for(auto i(0); i < p.length(); ++i){
        hashS[s[i]-'a']++;
        hashP[p[i]-'a']++;
    }
    if(hashS==hashP){
        count++;
    }
    for(auto j(p.length()); j < s.length(); ++j){
        hashS[s[j]-'a']++;
        hashS[s[j-p.length()]-'a']--;
        if(hashS==hashP){
            count++;
        }
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    int k; cin >> k;
    string p;

    vector<int> patterns;
    vector<string> temp;
    
    for(auto i(0); i < k; ++i){
        cin >> p;
        int ct = countPatterns(s,p);
        patterns.emplace_back(ct);
    }
    for(auto &y : patterns){
        cout << y << endl;
    }
    return 0;
}