// CodeForce Problem 981A

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static bool is_palindrome(string s){
		string rev = s;
		reverse(rev.begin(),rev.end());
		return rev==s;
	}
	static int longest_nonpal(string &s){
		vector<int> res;
		for(auto i = 0; i < s.size(); i++){
			for(auto j = 1; j <= s.size()-i; j++){
				if(!is_palindrome(s.substr(i,j)))
					res.emplace_back(s.substr(i,j).size());
			}
		}
		return(res.size()!=0 ? *max_element(res.begin(),res.end()) : 0);
	}	
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	cout << Solution::longest_nonpal(s);
	return 0;
}

