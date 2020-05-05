// Longest palindromic substring - O(N³) complexity

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static bool isPalindrome(string &s){
		int n = s.length();
		for(auto i = 0; i < n/2; ++i){
			if(s[i]!=s[n-1-i])
				return false;
		}
		return true;
	}
	static void longestPalindrome(string &str){
		vector<string> res;
		string temp = "";
		int max = 0;
		for(auto i = 0; i < str.length(); ++i){
			for(auto j = 1; j <= str.length()-i; j++){
				temp=str.substr(i,j);
				if(isPalindrome(temp) && max < temp.length()){
					max = temp.length();
					res.emplace_back(temp);
				}
			}
		}
		cout << max << "\n";
		cout << res[res.size()-1];
	}
};
int main(){
	ios_base::sync_with_stdio(false);
	string test = "xoxoxbab"; // 5 xoxox
	Solution::longestPalindrome(test);
}
