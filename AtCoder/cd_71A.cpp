// CodeForce Problem 71A

#include <bits/stdc++.h>
using namespace std;


void too_long(string &s){
	int n = s.size();
	if(n <= 10)
		cout << s << "\n";
	else
		cout << s[0] << n-2 << s[n-1] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s;
	for(auto i = 0; i < n; i++){
		cin >> s;
		too_long(s);
	}
	return 0;
}
