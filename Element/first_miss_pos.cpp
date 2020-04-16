// First missing positive -O(N) time complexity O(1) extra space

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static int first_miss_pos(vector<int> &arr){
		int n = arr.size();
		bool in[n+1] = {false};
		for(auto i = 0; i < n; i++){
			if(arr[i] > 0 && arr[i] <= n){
				in[arr[i]]=true;
			}
		}
		for(auto i = 1; i <= n; i++){
			if(!in[i])
				return i;
		}
		return n+1;
	}
};
int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	vector<int> arr = {3,4,-1,1};
	cout << Solution::first_miss_pos(arr);
}

