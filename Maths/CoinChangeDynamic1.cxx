/*Coin change - Dynamic recursive approach.
Time complexity: O(n*k); where is the target sum and k the number of coin.*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fast_io ios::sync_with_stdio(false);

vector<int> coins;
const int inf = 1e9+7;
const int N = 1e8;

bool ready[N];
int value[N];

int solve(int x) {
	if(x < 0) {
		return inf;
	}
	if(x==0) {
		return 0;
	}
	if(ready[x]) {
		return value[x];
	}
	int best = inf;
	for(auto c : coins) {
		best = min(best,solve(x-c)+1);
	}
	ready[x]=true;
	value[x]=best;
	return best;
}

int main(int argc, char **argv) {
	fast_io;
	cin.tie(0);
	int k; cin >> k; // k number of coins
	int c;
	for(int i = 0; i < k; ++i) {
		cin >> c;
		coins.push_back(c);
	}
	int n; cin >> n; // n target sum
	cout << solve(n);
	return 0;
}