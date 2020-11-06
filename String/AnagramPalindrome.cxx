// Anagram Palindrome
// Given a string S, Check if characters of the given string 
// can be rearranged to form a palindrome. 

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static void check(string s){
        unordered_map<char,int> h;
        auto c = 0;
        for(auto x : s)
            h[x]++;
        for(auto y : h){
            if(y.second==1)
                c++;
        }
        (c==1) ? printf("%s\n", "YES") : printf("%s\n", "NO");
    }
};

int main(){
    string s1 = "geeksogeeks";
    string s2 = "geeksforgeeks";
    Solution::check(s1); // YES
    Solution::check(s2); // NO
    return 0;
}