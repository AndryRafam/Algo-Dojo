// Longest Substring without repeated character

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static bool compare(string &s1, string &s2){ // compare the size of the string
        return s1.size() < s2.size();
    }
    static bool unique(string &s){ // check if there is a repeated character
        unordered_map<char,int> hash;
        for(auto i = 0; i < s.length(); ++i)
            hash[s[i]]++;
        for(auto &x : hash)
            if(x.second != 1)
                return false;
        return true;
    }
    static void longestSubstring(string &s){
        string temp = "";
        vector<string> str;
        for(auto i = 0; i < s.length(); ++i){
            for(auto j = 1; j <= s.length()-i; ++j){
                temp = s.substr(i,j);
                if(unique(temp))
                    str.emplace_back(temp);
            }
        }
        sort(str.begin(),str.end(),compare);
        cout << str[str.size()-1] << " -> " << str[str.size()-1].length();
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    string test = "pwwkeouwke";
    Solution::longestSubstring(test);
}
