// Longest palindromic substring - O(N²) complexity

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static bool isPalindrome(string &s){
		int n = s.length();
		unordered_map<char,int> hash;
		for(auto x = 0; x < n/2; ++x){
			hash[s[x]]++;
			hash[s[n-1-x]]--;
		}
		for(auto &i : hash)
			if(i.second!=0)
				return false;
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
	string test = "xoxobab";
	Solution::longestPalindrome(test);
}
