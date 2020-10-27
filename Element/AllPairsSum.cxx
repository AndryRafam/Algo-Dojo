// All Pairs that Sum to Target
// https://edabit.com/challenge/hTsL3mY96fpeTxqwD
// O(nLogn) time complexity

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static vector<pair<int,int>> allPairs(vector<int> arr, int target){
		vector<pair<int,int>> res;
		sort(arr.begin(),arr.end());
		int n = arr.size();
		int lo = 0;
		int hi = n-1;
		while(lo < hi){
			if(arr[lo]+arr[hi]==target){
				res.emplace_back(arr[lo],arr[hi]);
				lo++; hi--;
			}
			else if(arr[lo]+arr[hi] < target){
				lo++;
			}
			else{
				hi--;
			}
		}
		return res;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	vector<int> arr = {4, 5, 1, 3, 6, 8};
	int target = 9;
	for(auto x : Solution::allPairs(arr,target)){
		cout << x.first << " " << x.second << endl; // [[1 8], [3 6], [4 5]]
	}
	return 0;
}
