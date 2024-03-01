#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    string s; getline(cin,s);
    vector<int> count(26,0);
    int cnt = 0;
    for(auto i = 0; i < s.size(); ++i){
        if(s[i]>='a' && s[i]<='z'){
            count[s[i]-'a']++;
            cnt++;
        }
        else if(s[i]>='A' && s[i]<='Z'){
            count[s[i]-'A']++;
            cnt++;
        }
    }
    for(auto i = 0; i < 26; ++i){
        cout << double(count[i])/cnt << "\n";
    }
    return 0;
}