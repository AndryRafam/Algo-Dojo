// Reverse words in a sentence
// To simplify, special character are dots and spaces only

// Time complexity: O(|s|) where |s| is the length of s

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:	
	static void rev (string s){
		int i = 0;
		for(auto j = 0; j < (int)s.size(); j++){
			if(s[j]==' ' || s[j]=='.'){
				reverse(s.begin()+i,s.begin()+j);
				i = j+1;
			}
		}
		reverse(s.begin()+i,s.end());
		reverse(s.begin(),s.end());
		for(auto &x : s)
			cout << x;
		cout << endl;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s = "This is your sentence. Reverse the words.";
	Solution::rev(s);
	return 0;
}
