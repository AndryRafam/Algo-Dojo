// Longest palindromic substring - O(N³) complexity

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static bool isPalindrome(string &s){
		int l = 0;
		int r = s.length()-1;
		while(l < r){
			if(s[l++]!=s[r--]){
				return false;
			}
		}
		return true;
	}
	static vector<pair<string,int>> longestPalindrome(string &str){
		vector<pair<string,int>> res;
		string temp = "";
		string max_str = "";
		int max = 0;
		for(auto i(0); str[i]; ++i){
			for(auto j(1); j <= str.length()-i; ++j){
				temp = str.substr(i,j);
				if(isPalindrome(temp) && max < temp.length()){
					max = temp.length();
					max_str = temp;
				}
			}
		}
		res.push_back({max_str,max});
		return res;
	}
};
int main(){
	ios_base::sync_with_stdio(false);
	string test = "xoxoxbaobab"; // 5 xoxox
	for(auto &x : Solution::longestPalindrome(test)){
		cout << x.first << " ";
	}
	return 0;
}
