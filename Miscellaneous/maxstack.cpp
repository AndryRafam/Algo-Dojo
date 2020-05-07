// Max element in stack O(N) complexity

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	stack<int> s;
	int k,n; cin >> n; // stack size (n=4)
	for(auto i = 0; i < n; i++){
		cin >> k; // 1 4 2 3
		s.push(k);
	}
	int max = s.top();
	while(!s.empty()){
		if(max <= s.top())
			max = s.top();
		s.pop();
	}
	cout << max; // 4
	return 0;
}
