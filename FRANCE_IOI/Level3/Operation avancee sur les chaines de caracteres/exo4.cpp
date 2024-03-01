#include <bits/stdc++.h>
using namespace std;

map<string,string> mp;
int n;

int main(){
    ios::sync_with_stdio(false);
    string s1,s2;
    cin >> n;
    cin.ignore();
    for(auto i = 0; i < n; ++i){
        cin >> s1 >> s2;
        mp[s2]=s1;
    }
    for(auto &it : mp){
        cout << it.first << " " << it.second << "\n";
    }
    return 0;
}