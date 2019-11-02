// Greatest Common Subsequence: TryAlgo Problem. O(m*n) complexity

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static void GCS(vector<int> &arr1, vector<int> &arr2){
        int m = arr1.size();
        int n = arr2.size();
        int dp[m+1][n+1];
        for(int i = 0; i <=m; ++i){
            for(int j = 0; j <= n; ++j){
                if(i == 0 || j == 0)
                    dp[i][j]=0;
                else if (arr1[i-1]==arr2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        // code which enable to print the common element
        int index = dp[m][n];
        stack<int> gcs;
        int i = m, j = n;
        while(i > 0 && j > 0){
            if(arr1[i-1]==arr2[j-1]){
                    gcs.push(arr1[i-1]);
                    i--; j--; index--;
            }
            else if(dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }
        cout << dp[m][n] << "\n";
        while(!gcs.empty()){
            cout << gcs.top() << " ";
            gcs.pop();
        }
    }
};
int main(){
    vector<int> test1 = {1,4,5,-12};
    vector<int> test2 = {-12,1,2,4};
    Solution::GCS(test1,test2);
}
