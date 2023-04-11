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
	static string longestPalindrome(string &str){
		string temp = "";
		string longest_pal = "";
		int max = 0;
		for(auto i(0); str[i]; ++i){
			for(auto j(1); j <= str.length()-i; ++j){
				temp = str.substr(i,j);
				if(isPalindrome(temp) && max < temp.length()){
					max = temp.length();
					longest_pal = temp;
				}
			}
		}
		return longest_pal;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	string test = "xoxoxbaobab"; // 5 xoxox
	cout << Solution::longestPalindrome(test);
	return 0;
}
