/*Let's define a function countUniqueChars(s) that returns the number of unique characters on s.

For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.

Given a string s, return the sum of countUniqueChars(t) where t is a substring of s. The test cases are generated such that the answer fits in a 32-bit integer.

Notice that some substrings can be repeated so in this case you have to count the repeated ones too.

Brute force approach: O(N³) time complexity, where N is the size of the string.

It takes O(N²) to generate all substrings of the string, and O(N) to count the number of unique characters.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    static int countUniqueChars(string s) {
        unordered_map<char,int> mp;

        for(auto x : s) {
            mp[x]++;
        }
        int count = 0;
        for(auto y : mp) {
            if(y.second > 1) {
                continue;
            }
            else {
                count++;
            }
        }
        return count;
    }
    static int uniqueLetterString(string s) {
        int total_count = 0;
        for(auto i(0); i < s.length(); ++i) {
            for(auto j(1); j <= s.length()-i; ++j) {
                total_count += countUniqueChars(s.substr(i,j));
            }
        }
        return total_count;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    string s;
    cin >> s;
    cout << Solution::uniqueLetterString(s) << "\n";
    return 0;
}
