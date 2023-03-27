/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Time complexity: O(N²)+O(NlogN) = O(N²+NlogN), sort the array first and then apply two pointers approach.
N is the size of the array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	static vector<vector<int>> threeSum(vector<int> &nums) {
		set<vector<int>> tmp;
		sort(nums.begin(),nums.end());
		for(int i(0); i < nums.size(); ++i) {
			int j = i+1;
			int k = nums.size()-1;
			while(j < k) {
				if(nums[i]+nums[j]+nums[k]==0) {
					tmp.insert({nums[i],nums[j],nums[k]});
					j++;
					k--;
				}
				else if(nums[i]+nums[j]+nums[k] < 0) {
					j++;
				}
				else {
					k--;
				}
			}
		}
		vector<vector<int>> result;
		for(auto &x : tmp) {
			result.emplace_back(x);
		}
		return result;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	vector<int> test = {-1,0,1,2,-1,-4};
	for(auto y : Solution::threeSum(test)) {
		for(auto x : y) {
			cout << x << " ";
		}
		cout << "\n";
	}
	return 0;
}
