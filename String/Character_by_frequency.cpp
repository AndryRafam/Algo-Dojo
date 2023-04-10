/*
Given a string s, sort it in decreasing order based on the frequency of the characters.
The frequency of a character is the number of times it appears in the string.
Return the sorted string. If there are multiple answers, return any of them.

Time complexity: O(N), N is the size of the string.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static string frequencySort(string &s){
        unordered_map<int,int> freq;
        for(auto &it : s){
            freq[it]++;
        }
        priority_queue<pair<int,int>> maxHeap;
        for(auto &j : freq){
            maxHeap.push({j.second,j.first});
        }
        string res = "";
        while(!maxHeap.empty()){
            int k = maxHeap.top().first;
            while(k > 0){
                res+=maxHeap.top().second;
                k--;
            }
            maxHeap.pop();
        }
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    cout << Solution::frequencySort(s) << "\n";
    return 0;
}