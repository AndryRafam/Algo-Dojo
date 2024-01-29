/*Coin change - Dynamic iterative approach.
Time complexity: O(n*k); where n is the target sum and k the number of coin.*/

#include <iostream>
#include <vector>
using namespace std;

#define fast_io ios::sync_with_stdio(false);

vector<int> coins;
const int inf = 1e9+7;
const int N = 1e8;
bool ready[N];
int value[N];

template <class T>
auto Min(const T &a, const T &b) {
	return (a < b) ? a:b;
}

int solve(int n) {
	value[0] = 0;
	for(int x = 1; x <= n; ++x) {
		value[x] = inf;
		for(auto c : coins) {
			if(x-c >= 0) {
				value[x] = Min(value[x],value[x-c]+1);
			}
		}
	}
	return value[n];
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
