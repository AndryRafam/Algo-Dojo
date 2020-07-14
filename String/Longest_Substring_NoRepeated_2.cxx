// Length of the longest substring without repeated character

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static bool unique(string s){
		unordered_map<char,int> hash;
		for(auto i = 0; i < (int)s.size(); ++i)
			hash[s[i]]++;
		for(auto &x : hash){
			if(x.second != 1){
				return false;
			}
		}
		return true;
	}
	static int lenOfLongSubstring(string s){
		string temp = "";
		vector<int> len;
		for(auto i = 0; i < (int)s.size(); ++i){
			for(auto j = 1; j <= (int)s.size()-i; ++j){
				temp = s.substr(i,j);
				if(unique(temp))
					len.emplace_back(temp.size());
			}
		}
		return *max_element(len.begin(),len.end());
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	string s = "abcabcbb"; // 3
	cout << Solution::lenOfLongSubstring(s) << endl;
	return 0;
}
