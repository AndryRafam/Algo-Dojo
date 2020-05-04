// O(N) complexity - N size of the array

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector<int> seq = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
	int k;
	cin >> k;
	vector<pair<int,int>> rank;
	for(auto i = 0; seq[i]; ++i){
		rank.emplace_back(seq[i],i+1);
	}
	for(auto &x : rank){
		if(x.second==k)
			cout << x.first;
	}
	return 0;
}

