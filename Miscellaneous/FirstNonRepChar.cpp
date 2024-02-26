#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false)

class Solution {
    public:
    static void firstNonRepChar(const string);
};

void Solution::firstNonRepChar(const string s) {
    if(s=="") {
        cout << "Invalid";
    }
    map<char,int> freq;
    for(size_t i = 0; i < s.size(); ++i) {
        freq[s[i]]++;
    }
    for(auto x : freq) {
        if(x.second==1) {
            cout << x.first;
            return;
        }
    }
    cout << "Invalid";
    return;
}

int main() {
    fast_io;
    cin.tie(0);
    string s; getline(cin,s);
    Solution::firstNonRepChar(s);
    return 0;
}