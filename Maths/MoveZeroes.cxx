/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
*/

#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums) {
    int n = nums.size();
    int next = 0;
    for(auto x : nums) {
        if(x!=0) {
            nums[next]=x;
            next++;
        }
    }
    for(auto i = next; i < n; ++i) {
        nums[i]=0;
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    for(auto y : nums){
        cout << y << " ";
    }
    return 0;
}
