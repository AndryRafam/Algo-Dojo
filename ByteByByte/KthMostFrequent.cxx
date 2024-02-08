// Given a list of strings, write a function to get the kth most frequently
// occurring string.

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

#define fast_io ios::sync_with_stdio(false)
#define ump unordered_map<string,int>
#define ppq priority_queue<pair<int,string>>
#define f first
#define s second

inline string kthMostFrequent(vector<string> &arr, int k) {
    ump freq;
    ppq pq;
    for(auto &x : arr) {
        freq[x]++;
    }
    for(auto &y : freq) {
        pq.push({y.s,y.f});
    }
    int t = pq.top().f-k;
    while(!pq.empty()) {
        if(pq.top().f==t) {
            return pq.top().s;
        }
        pq.pop();
    }
    return "null";
}

int main() {
    fast_io;
    cin.tie(0);
    vector<string> arr;
    int s; cin >> s; // vector size;
    string t;
    for(int i(0); i < s; ++i) {
        cin >> t;
        arr.push_back(t);
    }
    int k; cin >> k;
    cout << kthMostFrequent(arr,k);
    return 0;
}
