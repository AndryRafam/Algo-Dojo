/* LeetCode problem: 2009 - Minimum Number of Operations to Make Array Continuous.

You are given an integer array nums. In one operation, you can replace any element in nums with any integer.
Nums is considered continuous if both of the following conditions are fulfilled:

- All elements in nums are unique.
- The difference between the maximum element and the minimum element in nums equals nums.length - 1.

For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 5, 6] is not continuous.
Return the minimum number of operations to make nums continuous.

Time complexity: O(M)+O(N*LogN) = O(M+N*LogN); where M is the size of the array nums; N is the size of the array
of unique elements.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int minOperations(vector<int> nums){
        int n = nums.size();
        unordered_set<int> st;
        for(auto &e : nums){
            st.insert(e);
        }
        vector<int> arr_unique;
        for(auto &c : st){
            arr_unique.emplace_back(c);
        }
        sort(arr_unique.begin(),arr_unique.end());
        int m = arr_unique.size();
        int l = 0;
        int ans = n;
        for(auto r(0); r < m; ++r){
            while(l < m and arr_unique[l] < arr_unique[r]+n){
                ++l;
            }
            ans = min(ans,n-l+r);
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(false);
    vector<int> testcase1 = {1,2,3,5,6};
    vector<int> testcase2 = {1,10,100,1000};
    cout << Solution::minOperations(testcase1) << "\n"; // 1
    cout << Solution::minOperations(testcase2) << "\n"; // 3
    return 0;
}
