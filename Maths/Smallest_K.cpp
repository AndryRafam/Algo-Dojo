/*Given an array of integer and an integer k, return the k smallest element of the array.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> smallest_k(vector<int> arr, int k) {
    priority_queue<int> maxHeap;
    
    for(auto i(0); i < k; ++i) {
        maxHeap.push(arr[i]);
    }
    for(auto i(k); i < arr.size(); ++i) {
        if(arr[i] < maxHeap.top()) {
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }
    vector<int> result;
    while(!maxHeap.empty()) {
        result.emplace_back(maxHeap.top());
        maxHeap.pop();
    }
    sort(result.begin(),result.end());
    return result;
}

int main() {
    int k;
    cin >> k;
    vector<int> arr = {25, 7, 20, 15, 9, 36, 50};
    for(auto x : smallest_k(arr,k)) {
        cout << x << " ";
    }
    return 0;
}
