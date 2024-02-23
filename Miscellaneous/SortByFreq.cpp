/*
Given an array A[] of integers, sort the array according to frequency of elements.
That is elements that have higher frequency come first.
If frequencies of two elements are same, then smaller number comes first.
*/

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false)

class Solution {
    public:
    static void sortByFreq(vector<int> );
};

class Compare {
    public:
    bool operator()(pair<int,int> a, pair<int,int> b) {
        if(a.first==b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};

void Solution::sortByFreq(vector<int> arr) {
    map<int,int> freq;
    priority_queue<pair<int,int>,vector<pair<int,int>>, Compare> maxheap;
    for(auto x : arr) {
        freq[x]++;
    }
    for(auto y : freq) {
        maxheap.push({y.second,y.first});
    }
    while(!maxheap.empty()) {
        int k = maxheap.top().first;
        while (k > 0) {
            cout << maxheap.top().second << " ";
            k--;
        }
        maxheap.pop();
    }
    cout << "\n";
}

int main() {
    fast_io;
    cin.tie(0);
    int T; cin >> T;
    for(int i = 1; i <= T; ++i) {
        int N,x;
        cin >> N;
        vector<int> arr;
        for(int j = 0; j < N; ++j) {
            cin >> x;
            arr.push_back(x);
        }
        Solution::sortByFreq(arr);
    }
    return 0;
}
