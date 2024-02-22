/*
Sort the colors. The famous Dutch flag problem.
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

Time complexity: O(n), where n is the size of the array.
*/

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false)

class Solution {
    public:
    static void sortColors(vector<int>&);
};

void Solution::sortColors(vector<int>& nums) {
    int lo = 0;
    int mid = 0;
    int hi = nums.size()-1;
    while(mid <= hi) {
        switch(nums[mid]) {
            case 0:
                swap(nums[lo++],nums[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(nums[mid],nums[hi--]);
                break;
        }
    }
}

int main() {
    fast_io;
    vector<int> nums = {2,0,2,1,1,0};
    Solution::sortColors(nums);
    for(auto num : nums) {
        cout << num << " ";
    }
    return 0;
}