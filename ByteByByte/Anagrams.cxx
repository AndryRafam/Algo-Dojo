// Given two strings, write a function to determine whether they are
// anagrams.

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

#define fast_io ios::sync_with_stdio(false)

template <typename T, typename U>
inline T isAnagram(const U &a, const U &b) {
    unordered_map<char,int> hash;
    if(a.size()!=b.size()) {
        return false;
    }
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
    cout << (isAnagram<bool,string>(a,b) ? "true":"false") << "\n";
    return 0;
}
