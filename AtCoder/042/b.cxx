#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<string> tab;
    int N,L; cin >> N >> L;
    string s,res="";
    for(auto i = 0; i < N; i++){
        cin >> s;
        tab.emplace_back(s);
    }
    sort(tab.begin(),tab.end());
    for(auto x : tab){
        if(x.size()==L)
            res+=x;
    }
    cout << res << "\n";
    return 0;
}