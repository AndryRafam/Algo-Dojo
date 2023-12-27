#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution1 {
    public:
    static int lengthOfLongestSubstring(string s) {
        int res = 0;
        vector<int> count(128);
        for(int l = 0,r = 0; r < s.length(); ++r) {
            ++count[s[r]];
            while(count[s[r]]>1) {
                --count[s[l++]];
            }
            res = max(res,r-l+1);
        }
        return res;
    }
};

class Solution2 {
    public:
    static int lengthOfLongestSubstring(string s) {
        unordered_set<int> hashset;
        int max_len = 0;
        int l = 0;
        int r = 0;
        while(r < s.length()) {
            if(hashset.find(s[r])==hashset.end()) {
                hashset.insert(s[r]);
                max_len = max(max_len,r-l+1);
                r++;
            } else {
                hashset.erase(s[l]);
                l++;
            }
        }
        return max_len;
    }
};

int main() {
    ios::sync_with_stdio(false);
    string s = "abcabcbb";
    cout << Solution2::lengthOfLongestSubstring(s);
    return 0;
}