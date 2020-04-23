/* Enough Array: You are given a sequence of positive integers of length N, A=a1,a2,…,aN, and an integer K. 

How many contiguous subsequences of A satisfy the following condition?

    (Condition) The sum of the elements in the contiguous subsequence is at least K

We consider two contiguous subsequences different if they derive from different positions in A, even if they are the same in content.

Note that the answer may not fit into a 32-bit integer type. ~https://atcoder.jp/contests/abc130/tasks/abc130_d */


#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static uint64_t num(vector<uint64_t> &arr, int k){
        uint64_t count = 0;
        int n = arr.size();
        for(auto i = 0; i < n; ++i){
            if(arr[i]>=k)
                ++count;
            uint64_t sum = arr[i];
            for(auto j = i+1; j < n; ++j){
                sum = sum+arr[j];
                if(sum>=k)
                    ++count;
            }
        }
        return count;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    vector<uint64_t> test = {103, 35322, 232, 342, 21099, 90000, 18843, 9010, 35221, 19352};
    cout << Solution::num(test,53462);
}
