/*
The function is given a string. Sort the characters and return a new string. Sorting conditions:

    Most frequent (case-specific) move in front.
    For the same frequency upper case characters move in front.
    For the same frequency and case sort them alphabetically.

Examples

frequencySort("tree") ➞ "eert"

frequencySort("cccaaa") ➞ "aaaccc"

frequencySort("Aabb") ➞ "bbAa"
*/

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

#define fastio ios::sync_with_stdio(false)

struct Compare {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        if(a.first!=b.first) {
            return a.first < b.first;
        }
        if(isupper(a.second)!=isupper(b.second)) {
            return islower(a.second);
        }
        return a.second > b.second;
    }
};

string frequencySort(string s) {
    string res = "";
    unordered_map<int,int> freq;
    priority_queue<pair<int,int>,vector<pair<int,int>>, Compare> maxheap;
    for(auto c : s) {
        freq[c]++;
    }
    for(auto x : freq) {
        maxheap.push({x.second,x.first});
    }
    while(!maxheap.empty()) {
        int k = maxheap.top().first;
        res+=string(k,maxheap.top().second);
        maxheap.pop();
    }
    return res;
}

int main() {
    fastio;
    cin.tie(0);
    string s; cin >> s;
    cout << frequencySort(s);
    return 0;
}
