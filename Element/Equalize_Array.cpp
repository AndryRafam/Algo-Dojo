/* Equalize array: Determine the minimum number of elements to delete, such that the remaining elements are all equals.

Example: [1,2,2,3] → [2,2] 

Complexity: O(N), N is the size of the array */

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static int min_equal(vector<int> &arr){
		unordered_map<int,int> count;
		int temp = 0;
		for(auto &i : arr)
			count[i]++;
		for(auto &x : count)
			if(temp < x.second)
				temp = x.second;
		return arr.size()-temp;
	}
};
int main(){
	vector<int> arr = {3,3,2,1,3}; // 2 (Remove 1 and 2)
	printf("%d",Solution::min_equal(arr));
}
