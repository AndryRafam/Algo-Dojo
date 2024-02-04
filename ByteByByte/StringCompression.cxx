// Given a string, write a function to compress it by shortening every
// sequence of the same character to that character followed by the number of
// repetitions. If the compressed string is longer than the original, you should return
// the original string.

#include <iostream>
#include <string>
#include <map>
using namespace std;

#define fast_io ios::sync_with_stdio(false)

template <class T>
T compress(const T &s) {
	map<char,int> mp;
	for(auto c : s) {
		mp[c]++;
	}
	T str;
	for(auto x : mp) {
		str+=x.first+to_string(x.second);
	}
	return(str.size() < s.size() ? str:s);
}

int main(int argc, char **argv) {
	fast_io;
	cin.tie(0);
	string s; cin >> s;
	cout << compress(s);
	return 0;
}
