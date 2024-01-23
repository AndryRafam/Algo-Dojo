#include <iostream>
using namespace std;

#define fast_io ios::sync_with_stdio(false);

int main(int argc, char **argv) {
	fast_io;
	cin.tie(0);
	int n; cin >> n;
	int fib[n];
	fib[0]=0;
	fib[1]=1;
	for(int i = 2; i <= n; ++i) {
		fib[i]=fib[i-1]+fib[i-2];
	}
	cout << fib[n];
	return 0;
}