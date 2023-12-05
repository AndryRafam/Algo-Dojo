/*
4 SUM problem

Given an array nums of n integers, return an array of all the unique quadruplets 
[nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target){
    vector<vector<int>> st;
    if(nums.size() < 4){
        return st;
    }
    sort(nums.begin(),nums.end());
    for(auto i = 0; i < nums.size()-3; ++i){
        for(auto j = i+1; j < nums.size()-2; ++j){
            int lp = j+1;
            int rp = nums.size()-1;
            while(lp < rp){
                int tmp = nums[i]+nums[j]+nums[lp]+nums[rp];
                if(tmp==target){
                    st.push_back({nums[i],nums[j],nums[lp],nums[rp]});
                    lp++;
                    rp--;
                }
                else if(tmp < target){
                    lp++;
                }
                else{
                    rp--;
                }
            }
        }
    }
    return st;
}

int main(){
    ios_base::sync_with_stdio(false);
    vector<int> arr = {1,0,-1,0,-2,2};
    int target = 0;
    for(auto x : fourSum(arr,target)){
        for(auto y : x){
            cout << y << " ";
        }
        cout << "\n";
    }
    return 0;
}
