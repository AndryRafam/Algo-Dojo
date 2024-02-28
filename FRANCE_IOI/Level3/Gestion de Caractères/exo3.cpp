#include <bits/stdc++.h>
using namespace std;

void transfo(const string &s){
    for(auto x : s){
        if((int)x>=97 && (int)x<=122){
            cout << (char)toupper(x);
        }
        else{
            cout << x;
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    string s; getline(cin,s);
    transfo(s);
    return 0;
}