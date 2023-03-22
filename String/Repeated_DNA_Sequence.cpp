/*
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.
Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) 
that occur more than once in a DNA molecule. You may return the answer in any order.

Time complexity: O(n+k), where n is the length of s and k is the size of the hash table.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    static vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> freq;
        vector<string> DNA;
        for(auto i(0); i < s.length(); ++i) {
            string temp = s.substr(i,10);
            freq[temp]++;
        }
        for(auto x : freq) {
            if(x.second > 1) {
                DNA.emplace_back(x.first);
            }
        }
        return DNA;
    } 
};

int main() {
    ios_base::sync_with_stdio(false);
    string test_case_1 = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    for(auto e : Solution::findRepeatedDnaSequences(test_case_1)) { // CCCCCAAAAA AAAAACCCCC
        cout << e << " ";
    }
    cout << "\n";
    string test_case_2 = "AAAAAAAAAAAAA";
    for(auto e : Solution::findRepeatedDnaSequences(test_case_2)) { // AAAAAAAAAA
        cout << e << " ";
    }
    return 0;
}