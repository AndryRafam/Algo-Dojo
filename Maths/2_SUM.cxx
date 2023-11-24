/*Given an array of size N and a number "c", determine whether or not there exist pairs of numbers "a" and "b", 
such that a+b=c. If there is an answer, return their indices.

Time Complexity: O(N)
Space Complexity: O(N)*/

#include<bits/stdc++.h>
using namespace std;

vector<int> pairExist(vector<int> arr, int c){
	unordered_map<int,int> hashmap;
	for(int i = 0; i < arr.size(); ++i){
		int cmp = c - arr[i];
		if(hashmap.find(cmp)!=hashmap.end()){
			return{hashmap[cmp],i};
		}
		// add the current element and its index to the map
		hashmap[arr[i]]=i;
	}
	// no solution found
	return{};
}

int main(){
	vector<int> nums;
	int size;
	scanf("%d",&size);
	for(int i = 0; i < size; ++i){
		int t;
		scanf("%d",&t);
		nums.emplace_back(t);
	}
	for(int x : pairExist(nums,60)){
		printf("%d ",x);
	}
	return 0;
}
