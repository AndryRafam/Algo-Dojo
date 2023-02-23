/* Given an array of size N and a number "c", determine whether or not there exist pairs of numbers "a" and "b", such that a+b=c.
In this exercise, you don't need to return the pairs.

Time Complexity: O(N)
Space Complexity: O(N)*/

#include<bits/stdc++.h>
using namespace std;

static bool pair_exist(vector<int> &arr, int c){
    vector<int>::iterator it;
	for(auto &x : arr){
		it = find(arr.begin(),arr.end(),c-x);
		if(it!=arr.end())
			return true;
	}
	return false;
}

int main(int argc, char **argv){
	vector<int> arr = {10,50,20,35,80,78};
	string res;
	res = (pair_exist(arr,130)==true) ? "YES":"NO";
	cout << res;
}
