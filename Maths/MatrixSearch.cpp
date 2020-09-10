/* Search in NxM sorted Matrix - O(NlogM) time complexity */

#include <bits/stdc++.h>
using namespace std;

bool IsIn(vector<vector<int>> A, int N, int M, int B){
    for(auto i = 0; i < N; i++){
        if(binary_search(A[i].begin(), A[i].end(),B))
            return true;
    }
    return false;
}

int main(){
    vector<vector<int>> A = {{1,3, 5, 7},
                             {10,11,16,20},
                             {23,30,34,50}};
    int N = 3; int M = 4;
    int B = 3;
    cout << IsIn(A,N,M,B) << endl; // 1
    return 0;
}