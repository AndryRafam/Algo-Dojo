// Longest Ordered Subsequence: TryAlgo Problem - O(N^2) Complexity

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int LOS(vector<int> &arr){
        int n = arr.size();
        int dp[n+1] = {0};
        for(auto k = 0; k < n; ++k){
            dp[k] = 1;
            for(auto i = 0; i < k; ++i){
                if(arr[i] < arr[k])
                    dp[k]=max(dp[k],dp[i]+1);
            }
        }
        return *max_element(dp,dp+n);
    }
};
int main(){
    vector<int> test = {1,7,3,5,9,4,8};
    printf("%d",Solution::LOS(test));
}
