// Remove Duplicates from a Sorted Array
// O(N) time complexity

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static int rem(vector<int> arr){
		arr.erase(unique(arr.begin(),arr.end()),arr.end());
		return arr.size();
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector<int> arr = {1,1,1,2,2,3};
	cout << Solution::rem(arr) << endl; // 3
	return 0;
}
		


