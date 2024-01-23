#include <iostream>
#include <string>
#include <map>
using namespace std;

#define fast_io ios::sync_with_stdio(false)

string compress(string s) {
	map<char,int> mp;
	for(auto c : s) {
		mp[c]++;
	}
	string str;
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