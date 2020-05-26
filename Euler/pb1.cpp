#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int n = 1000, sum = 0;
	for(auto i = 3; i < n; i++){
		if(i%3==0 || i%5==0)
			sum+=i;
	}
	cout << sum << endl;
	return 0;
}
