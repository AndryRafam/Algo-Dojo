#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int N;
	cin >> N;
	string s;
	vector<string> tab;
	for(auto i = 0; i < N; i++){
		cin >> s;
		tab.emplace_back(s);
	}
	sort(tab.begin(),tab.end());
	for(auto x : tab)
		cout << x;
	return 0;
}

