/*
Given a string str, convert it to a palindrome by adding characters to the front of it.
Find the minimum number of characters needed in the front of str to make it a palindrome.
A palindrome is a sequence that can be read the same way backward or forward.

Time complexity: O(N); where N is the size of the string.
*/

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false)

int minCostPalindrome(const string str) {
    int n = str.size();
    int l = 0, r = n-1;
    int count = 0;
    while(l < r) {
        if(str[l]!=str[r]) {
            count++;
            r--;
        } else {
            l++;
            r--;
        }
    }
    return count;
}

int main() {
    fast_io;
    cin.tie(0);
    string s; cin >> s;
    cout << minCostPalindrome(s);
    return 0;
}