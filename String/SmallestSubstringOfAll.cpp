#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false)
#define ust unordered_set

class Solution {
    public:
    static string getShortestUniqueSubstring(vector<char> arr, string str) {
        vector<string> res;
        string t = "";
        for(size_t i = 0; i < str.length(); ++i) {
            for(size_t j = arr.size(); j <= str.length()-i; ++j) {
                t = str.substr(i,j);
                if(isUnique(t)==1) {
                    return t;
                }
            }
        }
        return "";
    }
    private:
    static bool isUnique(const string str) {
        ust <char> freq;
        for(auto c : str) {
            if(freq.find(c)!=freq.end()) {
                return false;
            }
            freq.insert(c);
        }
        return true;
    }
};

/*
bool isUnique(const string str) {
    ust <char> freq;
    for(auto c : str) {
        if(freq.find(c)!=freq.end()) {
            return false;
        }
        freq.insert(c);
    }
    return true;
}

string getShortestUniqueSubstring(vector<char> arr, string str) {
    vector<string> res;
    string t = "";
    for(size_t i = 0; i < str.length(); ++i) {
        for(size_t j = arr.size(); j <= str.length()-i; ++j) {
            t = str.substr(i,j);
            if(isUnique(t)==1) {
                return t;
            }
        }
    }
    return "";
}
*/

int main() {
    fast_io;
    cin.tie(0);
    vector<char> arr = {'x','y','z'};
    string str; cin >> str;
    cout << Solution::getShortestUniqueSubstring(arr,str);
    return 0;
}
