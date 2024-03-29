/*
Given an array A[] of integers, sort the array according to frequency of elements.
That is elements that have higher frequency come first.
If frequencies of two elements are same, then smaller number comes first.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
    static bool compare(const pair<int,int> &a, const pair<int,int> &b){
        if(a.second==b.second){
            return a.first < b.first;
        }
        return a.second > b.second;
    }
    public:
    static void sortByFrequency(vector<int> arr){
        unordered_map<int,int> freqMap;
        for(auto &x : arr){
            freqMap[x]++;
        }
        vector<pair<int,int>> freqPairs;
        for(auto &y : freqMap){
            freqPairs.emplace_back(y);
        }
        sort(freqPairs.begin(),freqPairs.end(),compare);
        for(auto &z : freqPairs){
            for(auto i = 0; i < z.second; ++i){
                cout << z.first << " ";
            }
        }
        cout << "\n";
        return;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    vector<int> arr1 = {5,5,4,6,4};
    vector<int> arr2 = {9,9,9,2,5};
    Solution::sortByFrequency(arr1);
    Solution::sortByFrequency(arr2);
    return 0;
}
