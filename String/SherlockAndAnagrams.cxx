// Sherlock and Anagrams
// Given a string, find the number of pairs of substrings of the string
// that are anagrams of each other.

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static bool is_anagram(string a, string b){
        unordered_map<char,int> h;
        if(a.size()!=b.size())
            return false;
        for(auto x(0); a[x]&&b[x]; x++){
            h[a[x]]++;
            h[b[x]]--;
        }
        for(auto &y : h){
            if(y.second!=0)
                return false;
        }
        return true;
    }
    static int SherlockAndAnagrams(string s){
        auto count = 0;
        vector<string> r;
        for(auto i(0); s[i]; i++){
            for(auto j(1); j <= (int)s.length()-i; j++){
                r.emplace_back(s.substr(i,j));
            }
        }
        for(auto i(0); i < (int)r.size(); i++){
            for(auto j(i+1); j < (int)r.size(); j++){
                if(is_anagram(r[i],r[j]))
                    count++;
            }
        }
        return count;
    }
};

int main(){
    string a = "kkkk";
    string b = "ifailuhkqq";
    cout << Solution::SherlockAndAnagrams(a) << endl; // 10
    cout << Solution::SherlockAndAnagrams(b) << endl; // 3
    return 0;
}
