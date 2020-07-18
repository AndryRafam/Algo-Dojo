// length  of the longest antipalindrome

#include <bits/stdc++.h>
using namespace std;

class Answer{
	public:
	static bool palindrome(string s){
		string rev = s;
		reverse(rev.begin(),rev.end());
		return (rev==s);
	}
	static int maxlen(string s){
		int max = 0;
		for(auto i = 0; i < (int)s.size(); i++){
			for(auto j = 1; j <= (int)s.size()-i; j++){
				int n = s.substr(i,j).size();
				if(!palindrome(s.substr(i,j)) && max < n)
					max = n;
			}
		}
		return max;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	string s = "wuffuw";
	cout << Answer::maxlen(s) << endl; //5
	return 0;
}
				

