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
        vector<int> pq;
        if((nums[0]-nums[n-1])>0){
            pq.emplace_back(abs(nums[0]-nums[n-1]));
        }
        for(auto x(0); x < n-1; x++){
            if((nums[x+1]-nums[x])>0)
                pq.emplace_back(nums[x+1]-nums[x]);
        }
        return (n>=2 ? *max_element(pq.begin(),pq.end()):0);
    }
};

int main(){
    vector<int> vec1 = {3,6,9,1};
    vector<int> vec2 = {10};
    printf("%d\n",Solution::maximumGap(vec1)); // 3
    printf("%d\n",Solution::maximumGap(vec2)); // 0
    return 0;
}