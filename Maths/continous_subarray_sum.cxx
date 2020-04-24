#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static bool checkSubarraySum(vector<int> &nums, int k){
        for(auto i = 0; nums[i]; ++i){
            if(nums[i]%k==0)
                continue;
            int sum = nums[i];
            for(auto j = i+1; nums[j]; ++j){
                sum = sum + nums[j];
                if(sum%k==0)
                    return true;
            }
        }
        return false;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    vector<int> nums = {23, 2, 6, 4, 7};
    int k = 6;
    cout << Solution::checkSubarraySum(nums,k);
}
