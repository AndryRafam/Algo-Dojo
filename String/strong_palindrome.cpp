/*AtCoder beginner contest 159: Strong palindrome*/

#include <bits/stdc++.h>
using namespace std;

class Answer{
	public:
	static bool is_palindrome(string &s){
		int n = s.size();
		for(auto i = 0; i < n/2; i++){
			if(s[i]!=s[n-1-i])
				return false;
		}
		return true;
	}
	static bool strong_palindrome(string &s){
		int n = s.size();
		string s1 = "";
		string s2 = "";
		for(auto i = 0; i < (n-1)/2; i++)
			s1 += s[i];
		for(auto j = (n+2)/2; j < n; j++)
			s2 += s[j];
		if(is_palindrome(s) & is_palindrome(s1) & is_palindrome(s2))
			return true;
		return false;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	string test = "akasaka";
	cout << Answer::strong_palindrome(test); // 1 (strong palindrome) 
}
