#include <bits/stdc++.h>
using namespace std;

bool unbalanced(string s){
    int n = s.size();
    unordered_map<char,int> count;
    for(auto x : s)
        count[x]++;
    for(auto itr : count){
        if(itr.second > n/2)
            return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    for(auto  i = 0; i < (int)s.size(); i++){
        for(auto j = 2; j <= (int)s.size()-i; j++){
            if(unbalanced(s.substr(i,j)))
                cout << s.substr(i,j) << "\n";
        }
    }
    return 0;
}