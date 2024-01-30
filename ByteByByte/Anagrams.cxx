#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

#define fast_io ios::sync_with_stdio(false);

bool isAnagram(const string &a, const string &b) {
    unordered_map<char,int> hash;
    for(int i = 0; a[i]&&b[i]; i++) {
        hash[tolower(a[i])]++;
        hash[tolower(b[i])]--;
    }
    for(auto &x : hash) {
        if(x.second!=0) {
            return false;
        }
    }
    return true;
}

int main() {
    fast_io;
    cin.tie(0);
    string a,b;
    cin >> a >> b;
    cout << (isAnagram(a,b) ? "true":"false") << "\n";
    return 0;
}
