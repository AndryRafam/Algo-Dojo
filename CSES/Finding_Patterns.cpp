//https://cses.fi/problemset/task/2102

#include <bits/stdc++.h>
using namespace std;

int findingPatterns(string &s, string &p){
    if(s.length() < p.length()){
        return 0;
    }
    int count = 0;
    vector<int> CountS(26,0);
    vector<int> CountP(26,0);

    for(auto i(0); i < p.length(); ++i){
        CountS[s[i]-'a']++;
        CountP[p[i]-'a']++;
    }
    if(CountS==CountP){
        count++;
    }
    for(auto j(p.length()); j < s.length(); ++j){
        CountS[s[j]-'a']++;
        CountS[s[j-p.length()]-'a']--;
        if(CountS==CountP){
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

    vector<int> pattern;
    vector<string> temp;

    for(auto i(0); i < k; ++i){
        cin >> p;
        int ct = findingPatterns(s,p);
        pattern.emplace_back(ct);
    }
    for(auto &y : pattern){
        if(y!=0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}