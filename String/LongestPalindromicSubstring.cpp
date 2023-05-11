/*Longest palindromic substring

Solution1: Naive approach, O(N³) time complexity.
Solution2-3: Expand around the center, O(N²) time complexity.
*/

#include <bits/stdc++.h>
using namespace std;

// Naive approach
class Solution1{
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

// Expand around the center, 1st version: deal with odd len and even len separately
class Solution2{
	private:
	static int expandCenter(string s, int l, int r){
		while(l >= 0 and r < s.size() and s[l]==s[r]){
			--l;
			++r;
		}
		return r-l-1;
	}
	public:
	static string longestPalindrome(string s){
		if(s.size() < 2){
			return s;
		}
		int start = 0;
		int end = 0;
		for(auto i(0); i < s.size(); ++i){
			int odd_len = expandCenter(s,i,i);
			int even_len = expandCenter(s,i,i+1);
			int len = max(odd_len,even_len);
			if(len > end-start){
				start = i-((len-1) >> 1);
				end = i+(len >> 1);
			}
		}
		return s.substr(start, end-start+1);
	}
};

// Expand around the center, 2nd version: deal with odd len and even len at the same time
class Solution3{
	public:
	static string longestPalindrome(string s){
		string s_prime = "#";
		for(auto &c : s){
			s_prime+=c+string("#");
		}
		int start = 0;
		int end = 0;
		int center = 0;
		while(center < s_prime.length()){
			int radius = 0;
			int l = center-(radius+1);
			int r = center+(radius+1);
			while(l >= 0 and r < s_prime.length() and s_prime[l--]==s_prime[r++]){
				radius++;
			}
			if(radius > end-start){
				start = (center-radius) >> 1;
				end = (center+radius) >> 1;
			}
			center++;
		}
		return s.substr(start,end-start);
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string test; cin >> test;
	cout << Solution3::longestPalindrome(test);
	return 0;
}
