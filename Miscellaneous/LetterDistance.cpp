#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false)

int letterDistance(const string s, const string w) {
    int dist = 0;
    if(s.length()==w.length()) {
        for(size_t i = 0; s[i]&&w[i]; ++i) {
            dist+=abs(int(s[i])-int(w[i]));
        }
    } 
    else if(s.length() < w.length()) {
        for(size_t i = 0; i < s.length(); ++i) {
            dist+=abs(int(s[i])-int(w[i]));
        }
        dist=dist+(w.length()-s.length());
    } 
    else {
        for(size_t i = 0; i < w.length(); ++i) {
            dist+=abs(int(s[i])-int(w[i]));
        }
        dist=dist+(s.length()-w.length());
    }
    return dist;
}

int main() {
    fast_io;
    cin.tie(0);
    string s,w; cin >> s >> w;
    cout << letterDistance(s,w);
    return 0;
}