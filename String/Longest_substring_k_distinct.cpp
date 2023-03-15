/*
You are given a string s and an integer k. Your task is to find the longest substring of s that contains at most k distinct characters.
If there are multiple such substrings, return any one.

Write a function longest_substring_with_k_distinct_chars that takes a string s
and an integer k as input, and returns a string that is the longest substring of s
that contains at most k distinct characters.

Brute force approach.
*/


#include <bits/stdc++.h>
using namespace std;

bool comp(const string &a, const string &b) {
    return a.length() < b.length();
}

bool k_distinct(const string &s, int k) {
    unordered_map<char,int> hashMap;

    for(auto x : s) {
        hashMap[x]++;
    }
    if(hashMap.size() <= k) { // at most k distinct character
        return true;
    }
    return false;
}

string longest_substring_k_distinct(const string &s, int k) {
    vector<string> res;
    string temp = "";
    for(auto i(0); i < s.length(); ++i) {
        for(auto j(i); j <= s.length()-i; ++j) {
            temp = s.substr(i,j);
            if(k_distinct(temp,k)) {
                res.emplace_back(temp);
            }
        }
    }
    return *max_element(res.begin(),res.end(),comp);
}

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    int k;
    cin >> s >> k;
    cout << longest_substring_k_distinct(s,k);
    return 0;
}
