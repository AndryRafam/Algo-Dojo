// Reorganize String
// LeetCode Problem 767

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static string reorString(string s){
		priority_queue <pair<int,char>> pq;
		unordered_map <char,int> hash;
		for(auto x : s){
			hash[x]++;
		}
		for(auto y : hash){
			pq.push({y.second,y.first});
		}
		string res = "";
		while(!pq.empty()){
			pair<int,char> one = pq.top();
			pq.pop();
			if(pq.empty()){
				if(one.first > 1)
					return "";
				res += one.second;
				return res;
			}
			pair <int,char> two = pq.top();
			pq.pop();
			res += one.second;
			res += two.second;
			one.first--;
			two.first--;
			if(one.first)
				pq.push(one);
			if(two.first)
				pq.push(two);
		}
		return res;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	string test = "aaabbbbc";
	cout << Solution::reorString(test) << endl; // bababcba
	return 0;
}
