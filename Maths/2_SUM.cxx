/* Given an array of size N and a number "c", determine whether or not there exist pairs of numbers "a" and "b", 
such that a+b=c. If there is an answer, print their indices.

Time Complexity: O(N)
Space Complexity: O(N)*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static vector<int> pairExist(vector<int> &arr, int c){
		unordered_map<int,int> hashmap;
		vector<int> ans;
		for(auto i(0); i < arr.size(); ++i){
			int cmp = c-arr[i];
			if(hashmap.find(cmp)!=hashmap.end()){
				ans.emplace_back(hashmap[cmp]);
				ans.emplace_back(i);
				return ans;
			}
			hashmap[arr[i]]=i;
		}
		return ans;
	}
};

int main(int argc, char **argv){
	vector<int> arr = {10,50,20,35,80,78};
	for(auto &x : Solution::pairExist(arr,30)){
		cout << x << " ";
	}
	return 0;
}
