/*AtCoder beginner contest 159: Strong palindrome*/

#include <bits/stdc++.h>
using namespace std;

class Answer{
	private:
	static bool isPalindrome(string &s){
		int left = 0;
		int right = s.length()-1;
		while(left < right){
			if(s[left]!=s[right]){
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
	public:
	static bool strongPalindrome(string &s){
		int n = s.length();
		if(!(n&1)){
			return false;
		}
		int l = (n-1)/2;
		int r = ((n-1)+3)/2;
		
		string a = s.substr(0,l);
		string b = s.substr(r,n);
		
		
		if(isPalindrome(s) && isPalindrome(a) && isPalindrome(b)){
			return true;
		}
		return false;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	string s = "akasaka";
	cout << Answer::strongPalindrome(s); // 1 (strong palindrome)
	return 0; 
}
