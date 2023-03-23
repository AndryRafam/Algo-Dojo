/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, 
return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    static vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>> maxHeap;
        for(auto i(0); i < points.size(); ++i) {
            int dist = pow(points[i][0],2) + pow(points[i][1],2);
            maxHeap.push({dist,{points[i][0],points[i][1]}});
            if(maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        while(!maxHeap.empty()) {
            vector<int> tmp;
            tmp.emplace_back(maxHeap.top().second.first);
            tmp.emplace_back(maxHeap.top().second.second);
            ans.emplace_back(tmp);
            maxHeap.pop();
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
    int k = 2;
    for(auto i : Solution::kClosest(points,k)) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}