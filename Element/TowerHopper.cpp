// Tower hopper problem in O(N) complexity

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static int MinJump(vector<int> &arr){
		int n = arr.size();
		if(n<=1)
			return 0;
		int maxReach = arr[0];
		int step = arr[0];
		int jump = 1;
		for(int i = 1; i < n; ++i){
			if(i==n-1)
				return jump;
			if(i+arr[i] > maxReach)
				maxReach = i+arr[i];
			step--;
			if(step == 0){
				jump++;
				step = maxReach-i;
			}
		}
		return jump;
	}
};
int main(){
	vector<int> test = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	printf("%d",Solution::MinJump(test));
}
