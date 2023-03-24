/*
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

Time complexity: O(N*2^N), where N is the length of the string S.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> result;
vector<string> currentList;

class Solution {
    public:
    static vector<vector<string>> partition(string s) {
        dfs(0,s);
        return result;
    }
    private:
    static void dfs(int start, string &s) {
        if(start >= s.length()) {
            result.emplace_back(currentList);
        }
        for(auto end = start; end < s.length(); end++) {
            if(isPalindrome(s,start, end)) {
                // add current palindrome substring in the current list
                currentList.emplace_back(s.substr(start,end-start+1));
                // backtrack and remove the current palindrome substring from currentList
                dfs(end+1,s);
                currentList.pop_back();
            }
        }
    }
    static bool isPalindrome(string &s, int left, int right) {
        while(left < right) {
            if (s[left++]!=s[right--]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    string s = "aab";
    for(auto x : Solution::partition(s)) {
        for(auto y : x) {
            cout << y << " ";
        }
    }
    return 0;
}
