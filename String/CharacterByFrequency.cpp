/*
Given a string s, sort it in decreasing order based on the frequency of the characters.
The frequency of a character is the number of times it appears in the string.
Return the sorted string. If there are multiple answers, return any of them.
*/

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false)
#define pq priority_queue

class Solution{
    public:
    static string frequencySort(string s){
        unordered_map<char,int> freq;
        for(auto c : s){
            freq[c]++;
        }
        pq<pair<int,char>> maxHeap;
        for(auto j : freq){
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
    fast_io;
    cin.tie(0);
    string s;
    cin >> s;
    cout << Solution::frequencySort(s);
    return 0;
}
