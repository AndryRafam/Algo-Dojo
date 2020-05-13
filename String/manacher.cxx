// Manacher algorithm

#include <bits/stdc++.h>
using namespace std;

void manacher(string s){
    int m = s.size();
    string t = "^";
    //transform string
    for(auto i = 0; i < m; i++)
        t+="#"+s.substr(i,1);
    t+="#$";
    
    int n = t.size();
    int P[n];
    int c = 1, r = 1;
    int maxLen = 0;
    int centerIndex = 0;
    for(auto i = 2; i < n-1; i++){
        int mirror = 2*c-i;
        P[i] = max(0,min(r-i,P[mirror]));
        while(t[i+1+P[i]]==t[i-1-P[i]])
            P[i]++;
        if(i+P[i] > r){
            c = i;
            r = i+P[i];
        }
        if(P[i] > maxLen){
            maxLen = P[i];
            centerIndex = i;
        }
    }
    cout << s.substr((centerIndex-1-maxLen)/2,maxLen) << " -> " << maxLen << "\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    manacher(s);
    return 0;
}
