#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

#define fast_io ios::sync_with_stdio(false);

template <typename T>
T kthMostFrequent(vector<T> &arr, int k) {
    priority_queue<pair<int,T>> pq;
    unordered_map<T,int> freq;
    for(auto &x : arr) {
        freq[x]++;
    }
    for(auto &y : freq) {
        pq.push({y.second,y.first});
    }
    int t = pq.top().first-k;
    while(!pq.empty()) {
        if(pq.top().first==t) {
            return pq.top().second;
        }
        pq.pop();
    }
    return "null";
}

int main() {
    fast_io;
    cin.tie(0);
    vector<string> arr = {"a","b","c","a","b","a"};
    int k; cin >> k;
    cout << kthMostFrequent(arr,k);
    return 0;
}