// Most frequent word in array.
// If there is a tie, print any of them.

#include <bits/stdc++.h>
using namespace std;

void freq(vector<string> vec){
	priority_queue<pair<int,string>> pq;
	unordered_map<string,int> hash;
	for(auto x : vec){
		hash[x]++;
	}
	for(auto y : hash){
		pq.push({y.second,y.first});
	}
	if(!pq.empty()){
		cout << pq.top().second.c_str();
	}
	return;
}

int main(){
	ios_base::sycn_with_stdio(false);
	vector<string> vec = {"jones","paul","jones","jones","peter","peter","jackson","peter"};
	freq(vec);
	return 0;
}
