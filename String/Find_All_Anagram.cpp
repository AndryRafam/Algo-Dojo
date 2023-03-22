/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. 
You may return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

Time complexity: O(N) using sliding window techniques, where N is the length of s.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    static vector<int> findAnagrams (string s, string p) {
        if(s.length() < p.length()) {
            return {};
        }
        vector<int> res;
        vector<int> hashS(26,0);
        vector<int> hashP(26,0);
        for(auto x(0); x < p.length(); ++x) {
            hashS[s[x]-'a']++;
            hashP[p[x]-'a']++;
        }
        if(hashS == hashP){
            res.emplace_back(0);
        }
        for(auto i(p.length()); i < s.length(); ++i) {
            hashS[s[i]-'a']++;
            hashS[s[i-p.length()]-'a']--;
            if(hashS == hashP) {
                res.emplace_back(i-p.length()+1);
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    string s, p;
    cin >> s >> p;
    for(auto x : Solution::findAnagrams(s,p)) {
        cout << x << " ";
    }
    return 0;
}