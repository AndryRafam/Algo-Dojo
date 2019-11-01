// Jump Game: O(N) complexity

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static bool isReachable(vector<int> &arr){
		int n = arr.size();
		if(n <= 1)
			return true;
		int maxReach = 0;
		int step = 1;
		for(int i = 0; i < n; ++i){
			step--;
			if(i+arr[i] > maxReach){
				maxReach = i+arr[i];
				step = arr[i];
			}
			if(step == 0 && i < n-1)
				return false;
		}
		return true;
	}
};
int main(){
	vector<int> test1 = {2,3,1,1,4};
	vector<int> test2 = {3,2,1,0,4};
	printf("%d\n",Solution::isReachable(test1));
	printf("%d",Solution::isReachable(test2));
}
