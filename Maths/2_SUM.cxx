/* 2 Sum problem on a random array

   Complexity: O(N) if the array is already sorted
               O(NlogN) if the array is not sorted (we must sort first sort the array) */

// In this example, the array is not sorted (O(NlogN) complexity)

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static vector<pair<int,int>> two_sum(vector<int> &arr, int x){
		int n = arr.size();
		sort(arr.begin(),arr.end());
		int left = 0;
		int right = n-1;
        vector<pair<int,int>> tab;
		while(left < right){
			if(arr[left]+arr[right]==x){
				tab.emplace_back(arr[left],arr[right]);
				return tab;
			}
			else if(arr[left]+arr[right] < x)
				left++;
			else
				right--;
		}
		if(tab.empty())
			cout << "NO PAIRS";
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	vector<int> test = {10,50,20,35,80,78};
	int target = 130;
	for(auto x : Solution::two_sum(test,target))
		cout << x.first << " " << x.second;
}

