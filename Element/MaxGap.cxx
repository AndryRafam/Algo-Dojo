// Given an unsorted array, find the maximum difference 
// between the successive elements in its sorted form.
// Return 0 if the array contains less than 2 elements.

// https://leetcode.com/problems/maximum-gap/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int maximumGap(vector<int> &nums){
        int n = nums.size();
        auto max = 0;
        if((nums[0]-nums[n-1])>0){
            max=abs(nums[0]-nums[n-1]);
        }
        for(auto x(0); x < n-1; x++){
            auto t = nums[x+1]-nums[x];
            if(t>0 and max<=t)
                max=t;
        }
        return (n>=2 ? max:0);
    }
};

int main(){
    vector<int> vec1 = {3,6,9,1};
    vector<int> vec2 = {10};
    printf("%d\n",Solution::maximumGap(vec1)); // 3
    printf("%d\n",Solution::maximumGap(vec2)); // 0
    return 0;
}
