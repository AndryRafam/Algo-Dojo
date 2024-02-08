#include <iostream>
#include <vector>
using namespace std;

#define fast_io ios::sync_with_stdio(false)

template <typename T >
int Max(T &a, T &b) {
    return a < b ? b:a;
}

int matrixProduct(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int prod[m][n];
    prod[0][0] = matrix[0][0];
    for(int row = 1; row < m; row++) {
        prod[row][0] = matrix[row][0]*prod[row-1][0];
    }
    for(int col = 1; col < n; col++) {
        prod[0][col] = matrix[0][col]*prod[0][col-1];
    }
    for(int row = 1; row < m; row++) {
        for(int col = 1; col < n; col++) {
            prod[row][col] = Max(prod[row-1][col],prod[row][col-1])*matrix[row][col];
        }
    }
    return prod[m-1][n-1];
}

int main() {
    fast_io;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    cout << matrixProduct(matrix);
    return 0;
}
