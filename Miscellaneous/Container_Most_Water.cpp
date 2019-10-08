// Container with most water

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static int maxArea(vector<int> &height){
		int maxarea = 0, l = 0, h = height.size()-1;
		while (l < h){
			maxarea = max(maxarea,min(height[l],height[h])*(h-l));
			if(height[l] < height[h])
				l++;
			else
				h--;
		}
		return maxarea;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	vector<int> test = {1,8,6,2,5,4,8,3,7}; // 49
	cout << Solution::maxArea(test);
}
