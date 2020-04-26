// Subarray which sum equal zero ~ O(N²) time complexity

#include <bits/stdc++.h>
using namespace std;


class Solution{
	public:
	static bool sum_zero(vector<int> &arr){
		for (auto i = 0; i < arr.size(); i++){
			int sum = 0;
			for(auto j = i+1; j < arr.size(); j++){
				sum += arr[j];
				if(sum == 0)
					return true;
			}
		}
		return false;
	}
};
int main(){
	ios_base::sync_with_stdio(0);
	vector<int> test = {4, 2, -3, 1, 6}; // True
	cout << Solution::sum_zero(test);
}
