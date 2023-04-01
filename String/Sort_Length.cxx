/*
 * Create a function that takes a string and returns a string ordered by the length of the words.
 * From shortest to longest word. If there are words with the same amount of letters, order them alphabetically.
 * 
 * Time complexity: O(N*KlogK), where N is the length of the string and K the size of the array.
 */

#include <bits/stdc++.h>
using namespace std;


class Solution{
	private:
	static bool comp(string &a, string &b){
		if(a.size()==b.size()){
			return a < b;
		}
		return a.size() < b.size();
	}
	public:
	static vector<string> sortByLength(string &s){
		vector<string> ans;
		string temp = "";
		for(auto &x : s){
			if(x==' '){
				ans.emplace_back(temp);
				temp = "";
			}
			else{
				temp+=x;
			}
		}
		ans.emplace_back(temp);
		sort(ans.begin(),ans.end(),comp);
		return ans;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	getline(cin,s);
	for(auto &x : Solution::sortLength(s)){
		cout << x << " ";
	}
	return 0;
}



