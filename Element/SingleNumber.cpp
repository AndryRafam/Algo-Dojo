/*Given 2*n + 2 numbers, every numbers occurs twice except two, find them.
Example

Example 1:
	Input:  [1,2,2,3,4,4,5,3]
	Output:  [1,5]

Example 2:
	Input: [1,1,2,3,4,4]
	Output:  [2,3] */
	

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumberIII(vector<int> &A) {
        vector<int> res;
        unordered_map<int,int> hash;
        for(auto i:A)
            hash[i]++;
        for(auto x:hash)
            if(x.second==1)
                res.emplace_back(x.first);
        return res;
    }
};
