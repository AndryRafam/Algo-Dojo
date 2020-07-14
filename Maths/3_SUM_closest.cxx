// 3 SUM closest 2 pointers method - O(n²+nlogn) ~ O(n²) complexity

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static int ThreeSumClosest(vector<int> nums, int target){
		sort(nums.begin(),nums.end());
		int diff = INT_MAX;
		int n = nums.size();
		for(auto i = 0; i < n && diff!=0; i++){
			int lo = i+1;
			int hi = n-1;
			while(lo < hi){
				int sum = nums[i]+nums[lo]+nums[hi];
				if(abs(target-sum) < abs(diff)){
					diff = target - sum;
				}
				else if(sum < target){
					lo++;
				}
				else{
					hi--;
				}
			}
		}
		return target-diff;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	vector<int> nums = {-1,2,1,-4};
	cout << Solution::ThreeSumClosest(nums,1) << endl;
	return 0;
}
			

