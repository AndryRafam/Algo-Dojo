// Find the Odd Integer
// https://edabit.com/challenge/wgnmQTbfssuhvZHqe

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static void findOdd(vector<int> arr){
		unordered_map<int,int> hash;
		for(auto &t : arr){
			hash[t]++;
		}
		for(auto &x : hash){
			if(x.second&1)
				cout << x.first << endl;
		}
		return;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	vector<int> test = {20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5};
	Solution::findOdd(test);
	return 0;
}
