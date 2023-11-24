/*
Hidden Anagram: https://edabit.com/challenge/vxWGJmtjpWtu36xfj

Create a function that takes two strings. The first string contains a sentence containing the 
letters of the second string in a consecutive sequence but in a different order. The hidden
anagram must contain all the letters, including duplicates, from the second string in any
order and must not contain any other alphabetic characters.

Write a function to find the anagram of the second string embedded somewhere in the first
string. You should ignore character case, any spaces, and punctuation marks and return the
anagram as a lower case string with no spaces or punctuation marks.

Time Complexity: O(N) using sliding window, where N is the length of the first string.
*/


#include <bits/stdc++.h>
using namespace std;

string ignore_others(string s){
    string t = "";
    for(auto x :s){
        if((int(x)>=65&&int(x)<=90)||(int(x)>=97&&int(x)<=122)){
                t+=tolower(x);   
        }
    }
    return t;
}

string hiddenAnagram(string a, string b){
    if(a.length() < b.length()){
        return "not found";
    }
    string x = ignore_others(a).c_str();
    string y = ignore_others(b).c_str();
    vector<int> res;
    vector<int> countX(26,0);
    vector<int> countY(26,0);
    for(int i = 0; i < y.length(); ++i){
        countX[x[i]-'a']++;
        countY[y[i]-'a']++;
    }
    if(countX==countY){
        res.emplace_back(0);
    }
    for(int i = y.length(); i < x.length(); ++i){
        countX[x[i]-'a']++;
        countX[x[i-y.length()]-'a']--;
        if(countX==countY){
            res.emplace_back(i-y.length()+1);
        }
    }
    if(res.empty()){
        return "not found";
    }
    return x.substr(res[0],y.length());
}

int main(){
    string a = "D  e b90it->?$ (c)a r...d,,#~";
    string b = "bad credit";

    string s = "An old west action hero actor";
    string t = "Clint Eastwood";
    
    cout << hiddenAnagram(a,b) << "\n"; // debitcard
    cout << hiddenAnagram(s,t); // noldwestactio

    return 0;
}
