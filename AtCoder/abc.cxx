#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int k;
	unordered_map<int,int> hash;
	for (auto i = 0; i < 3; i++){
		cin >> k;
		hash[k]++;
	}
	for(auto itr : hash){
		if(itr.first == 5 && itr.second == 2){
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
