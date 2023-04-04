/*
 * Given an array of integers that are out of order, determine the bounds of the smallest
 * window that must be sorted in order for the entire array to be sorted. 
 * For example, given [ 3 , 7 , 5 , 6 , 9] , you should return ( 1 , 3 ).
 * 
 * Time complexity: O(N), where N is the size of the array
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static vector<pair<int,int>> smallestWindow(vector<int> &arr){
		int start = 0;
		int end = 0;
		
		for(auto i(0); i < arr.size(); ++i){
			if(arr[i] > arr[i+1]){
				start = i;
				break;
			}
		}
		
		for(auto i(start+1); i < arr.size(); ++i){
			int max_so_far = max(arr[start],arr[i]);
			if(arr[i] < max_so_far){
				end = i;
			}
		}
		
		vector<pair<int,int>> ans;
		ans.emplace_back(start,end);
		return ans;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	vector<int> arr = {3 , 8 , 5 , 6 , 7}; // < 1, 4 >
	for(auto &x : Solution::smallestWindow(arr)){
		cout << x.first << " " << x.second;
	}
	return 0;
}

