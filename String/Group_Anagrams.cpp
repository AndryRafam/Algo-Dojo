/*Group anagrams.

Given an array of string, group the anagrams together.

Time complexity: O(Nklogk)

where N = size of array of string

and k = size of each string in the array.*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> group_anagrams(vector<string> str){
    unordered_map<string,vector<string>> mp;
    for(auto &x : str){
        string temp = x;
        sort(temp.begin(),temp.end());
        mp[temp].emplace_back(x);
    }
    vector<vector<string>> res;
    for(auto &y : mp){
        res.emplace_back(y.second);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    vector<string> vec = {"eat","tea","tan","ate","nat","bat"};
    for(auto i(0); i < group_anagrams(vec).size(); ++i) {
        for(auto j(0); j < group_anagrams(vec)[i].size(); ++j) {
            cout << group_anagrams(vec)[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
