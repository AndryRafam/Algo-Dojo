/*
https://cses.fi/problemset/task/1753

Time complexity: O(P)+O(N-P) = O(N), where N is the size of the string s,
and P is the size of the string p.
*/

#include <bits/stdc++.h>
using namespace std;

int stringMatch(string s, string p){
    if(s.length() < p.length()){
        return {};
    }
    vector<int> res;
    vector<int> hashS(26,0);
    vector<int> hashP(26,0);
    for(auto i(0); i < p.length(); ++i){
        hashS[s[i]-'a']++;
        hashP[p[i]-'a']++;
    }
    if(hashS==hashP){
        res.emplace_back(0);
    }
    for(auto j(p.length()); j < s.length(); ++j){
        hashS[s[j]-'a']++;
        hashS[s[j-p.length()]-'a']--;
        if(hashS==hashP){
            res.emplace_back(j-p.length()+1);
        }
    }
    return res.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    string s,p;
    cin >> s >> p;
    cout << stringMatch(s,p) << endl;
    return 0;
}