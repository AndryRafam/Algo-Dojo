// Find the majority elemment - O(N) complexity

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
		static int majority(vector<int> tab){
			unordered_map<int,int> count;
			for(auto &x : tab)
				count[x]++;
			for(auto &y : count)
				if(y.second > tab.size()/2)
					return y.first;
			return -1;
		}
};

int main(){
	vector<int> v = {1,2,5,9,5,5,5};
	vector<int> test = {1,5,3,2,2,4,7,8,9,8,9};
	printf("%d\n",Solution::majority(v));
	printf("%d",Solution::majority(test));
	return 0;
}
