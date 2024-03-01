#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n; cin >> n;
    cin.ignore();
    vector<string> str;
    string s;
    for(auto i = 0; i < n; ++i){
        getline(cin,s);
        str.push_back(s);
    }
    sort(str.begin(),str.end());
    for(auto x : str){
        cout << x << "\n";
    }
    return 0;
}