#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    set<char> voyelle = {'a','e','i','o','u','y'};
    for(auto c = 'a'; c <= 'z'; c++){
        if(voyelle.find(c)==voyelle.end()){
            cout << c << " ";
        }
    }
    return 0;
}