/*
Given two strings s0 and s1, each representing a sentence, return the number of unique words that are shared
between the two sentences.

Time complexity: O(m+n+k); where m is the length of s0, n is the length of s1 and k is the number of unique words
in the first sentence.
*/

#include <bits/stdc++.h>
using namespace std;

// Solution1
int solve(string s0, string s1){
    unordered_set<string> ust;
    string str0 = "";
    string str1 = "";
    vector<string> vec;
    for(auto i(0); i < s0.size(); ++i){
        if(s0[i]==' '){
            ust.insert(str0);
            str0="";
        }
        else{
            str0+=s0[i];
        }
    }
    ust.insert(str0);
    for(auto j(0); j < s1.size(); ++j){
        if(s1[j]==' '){
            vec.emplace_back(str1);
            str1="";
        }
        else{
            str1+=s1[j];
        }
    }
    vec.emplace_back(str1);
    int count = 0;
    for(auto &s : vec){
        if(ust.find(s)!=ust.end()){
            count++;
        }
    }
    return count;
}

// Solution2
int countCommonWords(string s0, string s1){
    unordered_set<string> words0, words1;
    istringstream iss_s0(s0), iss_s1(s1);
    string word;
    while(iss_s0 >> word){
        words0.insert(word);
    }
    while(iss_s1 >> word){
        words1.insert(word);
    }
    int count = 0;
    for(auto &w : words0){
        if(words1.find(w)!=words1.end()){
            count++;
        }
    }
    return count;
}

int main(){
    string s0 = "hello world hello oyster";
    string s1 = "world is your oyster";
    cout << countCommonWords(s0,s1) << endl; // 2
    cout << solve(s0,s1) << endl; // 2
    return 0;
}
