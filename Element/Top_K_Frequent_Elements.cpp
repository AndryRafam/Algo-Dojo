/*
Given an integer array nums and an integer k, return the k most frequent elements. 
You may return the answer in any order.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> freq;
        for(auto i : nums) {
            freq[i]++;
        }
        priority_queue<pair<int,int>> maxHeap;
        for(auto j : freq) {
            maxHeap.push({j.second,j.first});
        }
        while(k--) {
            ans.emplace_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    int k; cin >> k;
    vector<int> tab = {1,1,1,2,2,3};
    for(auto x : Solution::topKFrequent(tab,k)) { // [1 2], for k = 2
        cout << x << " ";
    }
    return 0;
}
