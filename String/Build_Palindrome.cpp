/*Given two string 'a' and 'b'; find a string 's' such that:

1) s = sa + sb, where 'sa' and 'sb' are non empty substring of 'a' and 'b'.

2) s is a palindromic string.

3) the length of is as long as possible.

If there are multiple answer, return the one who comes first alaphabetically. If there is no answer, return -1.

Brute force approach.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    static bool is_palindrome (string s) {
        int len = s.length();
        int l = 0;
        int r = len-1;

        while(l < r) {
            if(s[l]!=s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    static string build_palindrome (string a, string b) {
        vector<string> a_tab;
        vector<string> b_tab;
        vector<string> pal_tab; // tab to store all built palindrome

        for(auto i(0); i < a.length(); ++i) {
            for(auto j(1); j <= a.length()-i; ++j) {
                a_tab.emplace_back(a.substr(i,j));
            }
        }

        for(auto k(0); k < b.length(); ++k) {
            for(auto l(1); l <= b.length()-k; ++l) {
                b_tab.emplace_back(b.substr(k,l));
            }
        }

        for(auto x : a_tab) {
            for(auto y : b_tab) {
                if(is_palindrome(x+y)) {
                    pal_tab.emplace_back(x+y);
                }
            }
        }

        if (pal_tab.empty()) {
            return "-1";
        }

        int maxlen = 0;
        string candidate = "";

        for(auto s : pal_tab) {
            if(maxlen < s.length()) {
                maxlen = s.length();
                candidate = s;
            }
            else if(maxlen==s.length() && s < candidate) {
                candidate = s;
            }
        }
        return candidate;
    }
};

int main() {
    int q; // number of queries
    string a,b; // string a and b
    cin >> q;
    for (auto i(0); i < q; ++i) {
        cin >> a >> b;
        cout << Solution::build_palindrome(a,b) << "\n";
    }
    return 0;
}
