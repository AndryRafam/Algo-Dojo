// Most frequent word in array.
// If there is a tie, print any of them.

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static void freq (vector<string> vec){
	priority_queue<pair<string,int>> pq;        
	unordered_map<string,int> hash;
        for(auto &x : vec)
            hash[x]++;
	for(auto &y : hash)
		pq.push({y.first,y.second});
	if(!pq.empty()){
		cout << pq.top().first << endl;
		pq.pop();
	}
	return;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<string> vec = {"jones","paul","jones","jones","peter","peter","jackson","peter"};
    Solution::freq(vec);
    return 0;
}
