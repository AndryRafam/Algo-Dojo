// Affine Cipher Encrypt
// https://edabit.com/challenge/AQHcMKRr63ABCXNJo

// Here we are gonna use the ASCII standard

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static string affineEncrypt(string s, int a, int b){
		if(__gcd(a,26)!=1)
			return "";
		string res = "";
		for(auto x : s){
			res+= char((a*(int(x)-97)+b)%26+97);
		}
		return res;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	string test = "itahari";
	int a = 3, b = 2;
	cout << Solution::affineEncrypt(test,a,b) << endl; // ahcxcba
	return 0;
}
