// AtCoder Regular contest 058 - Problem F, O(N²) complexity


#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N,L;
	cin >> N >> L;
	string s;
	vector<string> tab;
	vector<string> res;
	for(auto i = 0; i < N; i++){
		cin >> s;
		tab.emplace_back(s);
	}
	for(auto i = 0; i < tab.size(); i++){
		for(auto j = i+1; j < tab.size(); j++){
			if((tab[i]+tab[j]).length() == L)
				res.emplace_back(tab[i]+tab[j]);
		}
	}
	cout << (res.empty() ? "Empty":*min_element(res.begin(),res.end()));
	return 0;
}

