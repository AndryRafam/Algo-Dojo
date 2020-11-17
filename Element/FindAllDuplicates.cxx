// Find all duplicates in an array

// Solution1: O(N) time complexity and O(N) extra space

// Solution2: O(N) time complexity and O(1) extra space

// https://leetcode.com/problems/find-all-duplicates-in-an-array/


#include <bits/stdc++.h>
using namespace std;

class Solution1{
    public:
    static vector<int> findDupl(vector<int>& nums){
        unordered_map<int,int> h;
        vector<int> res;
        for(auto x : nums)
            h[x]++;
        for(auto y : h){
            if(y.second==2)
                res.emplace_back(y.first); 
        }
        return res;
    }
};

class Solution2{
    public:
    static vector<int> findDupl(vector<int>& nums){
        vector<int> res;
        for(auto x : nums){
            if(nums[abs(x)]>=0)
                nums[abs(x)]*=-1;
            else
                res.emplace_back(abs(x));
        }
        return res;
    }
};

int main(){
    vector<int> nums = {4,3,2,7,8,2,3,1};
    for(auto x : Solution1::findDupl(nums))
        printf("%d ", x);
    printf("\n");
    for(auto x : Solution2::findDupl(nums))
        printf("%d ", x);
    printf("\n");
    return 0;
}
