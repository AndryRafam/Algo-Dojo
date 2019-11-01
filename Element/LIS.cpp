// Longest increasing subsequence - O(n^2) complexity

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int LIS(vector<int> &arr){
        int n = arr.size();
        int dp[n];
        for(auto i = 0; i < n; ++i){
            dp[i]=1;
            for(auto j = 0; j < i; ++j){
                if(arr[j] < arr[i])
                    dp[i] = max(dp[i],dp[j]+1);
            }
        }
        return *max_element(dp,dp+n);
    }
};
int main(){
    vector<int> test = {10, 22, 9, 33, 21, 50, 41, 60};
    printf("%d",Solution::LIS(test));
}
