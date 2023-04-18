/*
Given an array of non-negative integers, where each element represents the maximum number of steps that
can be jumped going forward from that element, write a function to return the minimum number of jumps
you must make in order to get from the start to the end of the array.

Time complexity: O(N²), where N is the size of the array.
*/

#include <bits/stdc++.h>
using namespace std;

#define int_max INT_MAX

class Solution{
    public:
    static int minJumps(vector<int> &arr){
        int n = arr.size();
        vector<int> dp(n,int_max);
        dp[0] = 0;
        for(auto i(0); i < n; ++i){
            for(auto j(i); j <= i+arr[i] && j < arr.size(); ++j){
                dp[j] = min(dp[j],dp[i]+1);
            }
        }
        return dp[n-1];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    vector<int> arr = {2, 3, 1, 1, 4};
    cout << Solution::minJumps(arr);
    return 0;
}