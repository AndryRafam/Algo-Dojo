// Letter Distance
// https://edabit.com/challenge/5Xo5fBrQui9opFWH5

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static int letterDistance(string s1, string s2){
		int m = s1.size();
		int n = s2.size();		
		int t = min(m,n);
		int mid = 0;		
		for(auto x = 0; x < t; x++){
			mid += abs((int)s1[x]-(int)s2[x]);
		}
		return mid+abs(m-n);
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	string s1 = "house";
	string s2 = "fly";
	cout << Solution::letterDistance(s1,s2) << endl;
	return 0;
}
