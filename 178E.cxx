/* AtCoder 178 e 
Maximal Manhattan distance */

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	vector<pair<int,int>> vec;
	int N; cin >> N;
	int x,y,max=0;
	for(auto i = 0; i < N; i++){
		cin >> x >> y;
		vec.emplace_back(x,y);
	}
	for(auto i = 0; i < (int)vec.size(); i++){
		for(auto j = i+1; j < (int)vec.size(); j++){
			if(max < abs(vec[i].first-vec[j].first)+abs(vec[i].second-vec[j].second)){
				max = abs(vec[i].first-vec[j].first)+abs(vec[i].second-vec[j].second);
			}
		}
	}
	cout << max << endl;
	return 0;
}
