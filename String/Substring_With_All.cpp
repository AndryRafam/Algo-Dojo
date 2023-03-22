/*
You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" 
are all concatenated strings. "acdbef" is not a concatenated substring because it is not the 
concatenation of any permutation of words.

Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.

Time complexity: O(k*n*l), where k is the size of words array; n is the length of the string s; l is the length
of the concatenation of all string in the words array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    static set<int> findSubstring(string s, vector<string> words) {
        string p = "";
        for(auto x : words) {
            p.append(x);
        }
        int k = words[0].length();
        set<int> ans;
        for(auto w : words) {
            size_t idx = s.find(w);
            while(idx < s.length()) {
                string temp = s.substr(idx,p.length());
                if(is_permut(temp,p)) {
                    ans.insert(idx);
                }
                idx+=k;
            }
        }
        return ans;
    }
    private:
    static bool is_permut(string a, string b) {
        if(a.length()!=b.length()) {
            return false;
        }
        unordered_map<char,int> hashA;
        unordered_map<char,int> hashB;
        for(auto x : a) {
            hashA[x]++;
        }
        for(auto y : b) {
            hashB[y]++;
        }
        return (hashA == hashB) ? true:false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    string test_case_1 = "barfoothefoobarman";
    vector<string> words_1 = {"foo","bar"};
    for(auto x : Solution::findSubstring(test_case_1,words_1)) { // [0 9]
        cout << x << " ";
    }
    cout << "\n";
    string test_case_2 = "wordgoodgoodgoodbestword";
    vector<string> words_2 = {"word","good","best","word"};
    for(auto x : Solution::findSubstring(test_case_2,words_2)) { // []
        cout << x << " ";
    }
    cout << "\n";
    string test_case_3 = "barfoofoobarthefoobarman";
    vector<string> words_3 = {"bar","foo","the"};
    for(auto x : Solution::findSubstring(test_case_3,words_3)) { // [6 9 12]
        cout << x << " ";
    }
    cout << "\n";
    string test_case_4 = "foobarfoobar";
    vector<string> words_4 = {"foo","bar"};
    for(auto x : Solution::findSubstring(test_case_4,words_4)) { // [0 3 6]
        cout << x << " ";
    }
    return 0;
}
