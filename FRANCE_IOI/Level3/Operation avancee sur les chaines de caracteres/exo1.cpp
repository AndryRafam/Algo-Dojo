#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    vector<string> arr;
    int n; cin >> n;
    cin.ignore();
    string s;
    for(auto i = 0; i < n; ++i){
        getline(cin,s);
        arr.push_back(s);
    }
    int a = arr.size();
    for(auto j = 0; j < a; ++j){
        cout << arr[a-1-j] << "\n";
    }
    return 0;
}