#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int h, a, count = 1;
	cin >> h >> a;
	while(h-a > 0){
		count++;
		h = h-a;
	}
	cout << count;
	return 0;
}
