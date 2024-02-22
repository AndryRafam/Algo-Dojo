/*
K Closest Points to Origin
Second solution: use of priority_queue/min heap. 
Time complexity: O(Nlogk); where N is the size of the array.
*/

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false)
#define dpp pair<double,pair<int,int>>

class Solution {
    public:
    static vector<vector<int>> kClosest(vector<vector<int>>&, int);
};

vector<vector<int>> Solution::kClosest(vector<vector<int>>& points, int k) {
    int m = points.size();
    double dist = 0;
    vector<vector<int>> result;
    priority_queue<dpp,vector<dpp>,greater<dpp>> pq; // minHeap
    for(int row = 0; row < m; ++row) {
        dist = sqrt(pow(points[row][0],2)+pow(points[row][1],2));
        pq.push({dist,{points[row][0],points[row][1]}});
    }
    while(k > 0) {
        dpp p = pq.top();
        pq.pop();
        result.push_back({p.second.first,p.second.second});
        k--;
    }
    return result;
}

int main() {
    fast_io;
    cin.tie(0);
    vector<vector<int>> t = {{3,3},{5,-1},{-2,4}};
    int k; cin >> k;
    vector<vector<int>> ans(Solution::kClosest(t,k));
    for(size_t r = 0; r < ans.size(); ++r) {
        for(size_t c = 0; c < ans[0].size(); ++c) {
            cout << ans[r][c] << " ";
        }
        cout << "\n";
    }
    return 0;
}