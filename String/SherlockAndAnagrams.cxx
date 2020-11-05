// Sherlock and Anagrams
// Given a string, find the number of pairs of substrings of the string 
// that are anagrams of each other.

#include <bits/stdc++.h>
using namespace std;

bool is_anagram(string a, string b){
    auto count = 0;
    if(a.size()!=b.size())
        return false;
    for(auto x : a)
        count+=x;
    for(auto y : b)
        count-=y;
    return (count==0 ? true:false);
}

int SherlockAndAnagrams(string s){
    auto count = 0;
    vector<string> r;
    for(auto i(0); i < (int)s.length(); i++){
        for(auto j(1); j <= (int)s.length()-i; j++){
            r.emplace_back(s.substr(i,j));
        }
    }
    for(auto i(0); i < (int)r.size(); i++){
        for(auto j(i+1); j < (int)r.size(); j++){
            if(is_anagram(r[i],r[j]))
                count++;
        }
    }
    return count;
}

int main(){
    string a = "kkkk";
    string b = "ifailuhkqq";
    printf("%d\n",SherlockAndAnagrams(a)); // 10
    printf("%d\n",SherlockAndAnagrams(b)); // 3
    return 0;
}
