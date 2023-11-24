/*
Hidden Anagram: https://edabit.com/challenge/vxWGJmtjpWtu36xfj
Create a function that takes two strings. The first string contains a sentence containing the 
letters of the second string in a consecutive sequence but in a different order. The hidden
anagram must contain all the letters, including duplicates, from the second string in any
order and must not contain any other alphabetic characters.
Write a function to find the anagram of the second string embedded somewhere in the first
string. You should ignore character case, any spaces, and punctuation marks and return the
anagram as a lower case string with no spaces or punctuation marks.

Time Complexity: O(N) using sliding window, where N is the length of the first string.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p){
    if(s.length() < p.length()){
        return {};
    }
    vector<int> res;
    vector<int> hashS(26,0);
    vector<int> hashP(26,0);
    for(int i = 0; i < p.length(); ++i){
        hashS[s[i]-'a']++;
        hashP[p[i]-'a']++;
    }
    if(hashS==hashP){
        res.emplace_back(0);
    }
    for(int j = p.length(); j < s.length(); ++j){
        hashS[s[j]-'a']++;
        hashS[s[j-p.length()]-'a']--;
        if(hashS==hashP){
            res.emplace_back(j-p.length()+1);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    string s, p;
    cin >> s >> p;
    for(auto x : findAnagrams(s,p)){
        printf("%d ",x);
    }
    return 0;
}
