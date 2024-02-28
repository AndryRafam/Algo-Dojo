#include <bits/stdc++.h>
using namespace std;

bool palindrome(const string &s){
    string t = "";
    for(auto i = 0; s[i]; ++i){
        if(s[i]!=' '){
            t.push_back(char(tolower(s[i])));
        }
    }
    string r = t;
    reverse(t.begin(),t.end());
    return t==r;
}

int main(){
    ios::sync_with_stdio(false);
    int n; cin >> n;
    cin.ignore();
    string s;
    for(auto i = 0; i < n; ++i){
        getline(cin,s);
        if(palindrome(s)){
            cout << s << "\n";
        }
    }
    return 0;
}