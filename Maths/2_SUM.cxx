/* Given an array of size N and a number "c", determine whether or not there exist pairs of numbers "a" and "b", such that a+b=c

Time Complexity: O(N)
Space Complexity: O(N)*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static bool pair_exist(vector<int> &arr, int c){
		unordered_map<int,int> hashmap;
		for(auto i(0); i < arr.size(); ++i){
			int cmp = c-arr[i];
			if(hashmap.find(cmp)!=hashmap.end()){
				return true;
			}
			hashmap[arr[i]]=i;
		}
		return false;
	}
};

int main(int argc, char **argv){
	vector<int> arr = {10,50,20,35,80,78};
	string res;
	res = (Solution::pair_exist(arr,30)==true) ? "YES":"NO";
	cout << res;
	return 0;
}
