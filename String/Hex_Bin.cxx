// Hex to Binary
// https://edabit.com/challenge/NX5uRSLwuXwsqKfiR

// Author: Andry Rafam

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static string hex_bin(string s){
	string res = "";
    	unordered_map<char,string> match {{'A',"1010"},{'B',"1011"},{'C',"1100"},{'D',"1101"},{'E',"1110"},{'F',"1111"}};
		for(auto x : s){
			for(auto y : match){
				if(x==y.first)
					res+=y.second;
			}
    	}
		return res;
	}
};

int main(){
    ios_base::sync_with_stdio(false);
    string test = "0xFF";
    cout << Solution::hex_bin(test) << endl;
    return 0;
}
