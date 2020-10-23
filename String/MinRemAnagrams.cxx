// Minimum Removals to Make Two Strings Anagrams
// https://edabit.com/challenge/NBi75bkHrhTTxmxST

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static int minRem(string a, string b){
		int rem = 0;
		int t = a.size();
		for(auto x = 0; b[x]; x++){
			rem += count(a.begin(),a.end(),b[x]);
		}
		return t-rem;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	string s1 = "abcde";
	string s2 = "cab";
	if(s2.size() <= s1.size()){
		cout << Solution::minRem(s1,s2) << endl;
	}
	else
		cout << Solution::minRem(s2,s1) << endl;
	return 0;
}
