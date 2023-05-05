/*
Given a list of integers nums, return whether there’s an integer whose frequency in the list is same as its value.
Time complexity: O(N), where N is the size of nums.
*/

#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> nums){
    unordered_map<int,int> freq;
    for(auto &x : nums){
        ++freq[x];
    }
    for(auto &y : freq){
        if(y.second==y.first){
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    vector<int> nums = {7, 9, 3, 3, 3};
    cout << (solve(nums)==1 ? "true":"false") << endl; // true, 3 is the answer.
    return 0;
}