#include <bits/stdc++.h>
using namespace std;

bool isValid(const string &s){
    if(!(isalpha(s[0]) || s[0]=='_')){
        return false;
    }
    for(auto i = 1; i < s.size(); ++i){
        if(!(isalpha(s[i]) || isdigit(s[i]) || s[i]=='_')){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    int n; cin >> n;
    cin.ignore();
    string s;
    for(auto i = 0; i < n; ++i){
        getline(cin,s);
        if(isValid(s)){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
    return 0;
}