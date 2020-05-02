/*Check if any permutation of string is a palindrome O(N) complexity (N length of the string)

 Examples: ivicc → True (permutation of civic which is a palindrome)
           civic → True (palindrome itself)
		   livic → False
		   liciv → False */
		   
#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static void permut(string &s){
		unordered_map<char,int> hash;
		int odd_count = 0;
		for(auto &x : s)
			hash[x]++;
		for(auto &itr : hash){
			if(itr.second%2!=0)
				odd_count+=1;
		}
		cout << (odd_count > 1 ? 0:1);
	}
};
int main(){
	ios_base::sync_with_stdio(0);
	string test = "ivicc"; // True
	Solution::permut(test);
}
