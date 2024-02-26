#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define fastio ios::sync_with_stdio(false)

string longestNRS(const string s) {
    int start = 0, maxlen = 0;
    unordered_map<int,int> hashMap;
    string maxSubstr = "";
    for(int i = 0; i < s.length(); ++i) {
        if(hashMap.find(s[i])!=hashMap.end()) {
            start = max(start,hashMap[s[i]]+1);
        }
        if(i-start+1 > maxlen) {
            maxlen = i-start+1;
            maxSubstr = s.substr(start,maxlen);
        }
        hashMap[s[i]]=i;
    }
    return maxSubstr;
}

int main() {
    fastio;
    cin.tie(0);
    string s; cin >> s;
    cout << longestNRS(s);
    return 0;
}