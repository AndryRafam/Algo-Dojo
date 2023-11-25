/*
Maximum Subarray Sum with Constraints

Problem Statement:
You are given an array arr of integers and an integer k. Your task is to find the maximum sum of a non-empty
subarray of arr such that the length of the subarray is less than or equal to k.

Time complexity of O(n) and a space complexity of O(1); where n is the size of the array.
*/

#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int> arr, int k){
    if(k > arr.size()){
        k = arr.size();
    }
    int window_sum = 0;
    for(size_t i = 0; i < k; ++i){
        window_sum += arr[i];
    }
    int max_sum = window_sum;
    for(size_t i = 0; i < arr.size()-k; ++i){
        window_sum = window_sum - arr[i]+arr[i+k];
        max_sum = max(window_sum,max_sum);
    }
    return max_sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArraySum(arr,4) << "\n";
    return 0;
}
