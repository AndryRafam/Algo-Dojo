/*
Given an array of integers, find the length of the longest increasing subarray.
An increasing subarray is a contiguous subarray in which the elements are in strictly increasing order.

Time complexity: O(N), N is the size of the array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int longestIncreasingSubArray(vector<int> &arr){
        if(arr.empty()){
            return {};
        }
        int current_len = 1;
        int max_len = 1;
        for(auto i(1); i < arr.size(); ++i){
            if(arr[i] > arr[i-1]){
                current_len += 1;
            }
            else{
                max_len = max(max_len,current_len);
                current_len += 1;
            }
        }
        return max(max_len,current_len);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    vector<int> arr = {1, 2, 3, 1, 2, 3, 4, 1};
    cout << Solution::longestIncreasingSubArray(arr) << "\n";
    return 0;
}