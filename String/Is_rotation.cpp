/*
You are given two strings s and t. Your task is to determine if s is a substring of t that can be obtained by rotating t 
by some number of positions to the left. Write a function is_rotation that takes two strings s and t as input, and returns
the number of rotation if s is a substring of t that can be obtained by rotating t by some number of positions to the left, 
and -1 otherwise.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    static int is_rotation(const string &s, const string &t) {
        if(s.length()!=t.length()) { // if s and t don't have the same, then s cannot be a rotation of t
            return -1;
        }
        string concat = t+t;
        int n = t.length();
        int pos = concat.find(s);
        if(pos != string::npos) {
            return pos%n;
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    cout << Solution::is_rotation(s,t) << "\n";
    return 0;
}