// Mini Sudoku
// https://edabit.com/challenge/JevwpdjTnoJT5t29F

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static bool isMiniSudoku(vector<vector<int>> square){
        unordered_map<int,int> hash;
        for(auto i = 0; i < (int)square.size(); ++i){
            for(auto j = 0; j < (int)square.size(); ++j){
                if(square[i][j]<1 || square[i][j]>9)
                    return false;
                hash[square[i][j]]++;
            }
        }
        for(auto x : hash){
            if(x.second!=1)
                return false;
        }
        return true;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    vector<vector<int>> square = {{1,3,2},{9,7,8},{4,5,6}}; // True
    cout << Solution::isMiniSudoku(square) << endl;
    return 0;
}
