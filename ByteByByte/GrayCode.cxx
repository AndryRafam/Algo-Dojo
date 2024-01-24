#include <iostream>
using namespace std;

#define fast_io ios::sync_with_stdio(false)

bool gray(int a, int b) {
	return (__builtin_popcount(a^b)==1 ? true:false);
}

int main(int argc, char **argv) {
	fast_io;
	cin.tie(0);
	int a,b;
	cin >> a >> b;
	cout << (gray(a,b)==1 ? "true":"false");
	return 0;
}