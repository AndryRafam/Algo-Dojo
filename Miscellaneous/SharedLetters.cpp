#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false)

class Solution {
    public:
    static int sharedLetters(const string , const string );
};

int Solution::sharedLetters(const string s, const string w) {
    int share = 0;
    unordered_set<int> hashmap;
    for(size_t i = 0; i < s.size(); ++i) {
        hashmap.insert(s[i]);
    }
    for(auto x : w) {
        if(hashmap.find(x)!=hashmap.end()) {
            share++;
        }
    }
    return share;
}

int main() {
    fast_io;
    cin.tie(0);
    string s,w; cin >> s >> w;
    cout << Solution::sharedLetters(s,w);
    return 0;
}