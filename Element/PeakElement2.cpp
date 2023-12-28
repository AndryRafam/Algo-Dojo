#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    static vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int l = 0;
        int r = mat.size()-1;
        while(l < r) {
            int m  = (l+r) >> 1;
            if(ranges(mat[m]) >= ranges(mat[m+1])) {
                r=m;
            } else {
                l=m+1;
            }
        }
        return {l,getMaxIndex(mat[l])};
    }
    private:
    static int getMaxIndex(vector<int>& A) {
        pair<int,int> res {0,A[0]};
        for(size_t i = 1; i < A.size(); ++i) {
            if(A[i] > res.second) {
                res = {i,A[i]};
            }
        }
        return res.first;
    }
    private:
    static int ranges(vector<int>& A) {
        int max = A[0];
        for(size_t i = 0; i < A.size(); ++i) {
            if(A[i] > max) {
                max=A[i];
            }
        }
        return max;
    }
};

int main() {
    ios::sync_with_stdio(false);
    vector<vector<int>> mat = {{10,20,15},{21,30,14},{7,16,32}};
    for(auto x : Solution::findPeakGrid(mat)) {
        cout << x << " ";
    }
    return 0;
}
