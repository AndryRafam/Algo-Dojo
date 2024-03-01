#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    string s; getline(cin,s);
    unordered_map<char,int> hash;
    for(auto x : s){
        if(x!=' ')
            hash[toupper(x)]++;
    }
    char mostFreqLetter;
    int maxOccur = 0;
    for(auto &m : hash){
        if(m.second > maxOccur){
            maxOccur = m.second;
            mostFreqLetter = m.first;
        }
    }
    cout << char(mostFreqLetter);
    return 0;
}