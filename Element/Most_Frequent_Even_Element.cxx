/* Most frequent even element.

Given an integer array nums, return the most frequent even element.

If there is a tie, return the smallest one. If there is no such element, return -1.

Time complexity: Linear*/


#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int mostFrequentEven(vector<int>& nums){
        unordered_map<int,int> ct;
        for(auto &n : nums){
            if(n&1)
                continue;
            else
                ct[n]++;
        }
        int count_freq = 0;
        int min_most_freq = -1;
        for(auto &x : ct){
            if(x.second > count_freq){
                count_freq = x.second;
                min_most_freq = x.first;
            }
        }
        for(auto &x : ct){
            if(x.first < min_most_freq && x.second==count_freq)
                min_most_freq = x.first;
        }
        return min_most_freq;
    }
};

int main(int argc, char **argv){
    vector<int> nums1 = {29,47,21,41,13,37,25,7};
    vector<int> nums2 = {0,1,2,2,4,4,1};
    vector<int> nums3 = {4,4,4,9,2,4};
    cout << Solution::mostFrequentEven(nums1) << endl; // -1
    cout << Solution::mostFrequentEven(nums2) << endl; // 2
    cout << Solution::mostFrequentEven(nums3) << endl; // 4
    return 0;
}