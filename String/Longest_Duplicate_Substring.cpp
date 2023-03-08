/*Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.

Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".

Brute Force approach.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    static bool comp(string s1, string s2) {
        return s1.length() < s2.length();
    }
    static string longestDupSubst(string s) {
        vector<string> tab;
        vector<string> tab_res;
        for(auto i(0); i < s.length(); ++i) {
            for(auto j(1); j <= s.length()-i; ++j) {
                tab.emplace_back(s.substr(i,j));
            }
        }
        unordered_map<string,int> hash;
        for(auto x : tab) {
            hash[x]++;
        }
        for(auto y : hash) {
            if(y.second >= 2) {
                tab_res.emplace_back(y.first);
            }
        }
        if(tab_res.empty()) {
            return "";
        }
        return *max_element(tab_res.begin(),tab_res.end(),comp); // return the longest duplicate substring
    }
};

int main() {
    string str;
    cin >> str;
    cout << Solution::longestDupSubst(str) << "\n";
    return 0;
}