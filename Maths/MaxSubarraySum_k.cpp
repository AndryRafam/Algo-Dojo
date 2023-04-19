/*
You are given an array of integers arr and an integer k. Your task is to find the maximum sum of a non-empty
subarray of length at most k. The subarray should contain at least one element.
Write a function max_sum_subarray that takes the array arr and the integer k as input and returns
the maximum sum of a subarray of length at most k.

Time complexity: O(N), where N is the size of the array
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int maxSubarraySum_k(vector<int> &arr, int k){
        int max_sum = 0;
        int window_sum = 0; // sum of window of length k
        for(auto i(0); i < k; ++i){
            window_sum += arr[i];
        }
        for(auto i(k); i < arr.size(); ++i){
            window_sum += arr[i] - arr[i-k];
            max_sum = max(window_sum,max_sum);
        }
        return max_sum;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    vector<int> arr = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int k = 4;
    cout << Solution::maxSubarraySum_k(arr,k) << endl;
    return 0;
}