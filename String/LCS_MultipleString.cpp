/* Print the LCS of multiple string */

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static bool compare(string &s1, string &s2){
        return s1.size() < s2.size();
    }
    static string LCS(string &s1, string &s2){
        int m = s1.length();
        int n = s2.length();
        int dp[m+1][n+1];
        for(auto i = 0; i <= m; ++i){
            for(auto j = 0; j <= n; ++j){
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        stack<char> s;
        int i = m, j = n;
        while(i > 0 && j > 0){
            if(s1[i-1]==s2[j-1]){
                s.push(s1[i-1]);
                i--; j--;
            }
            else if (dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }
        string out = "";
        while(!s.empty()){
            out+=s.top();
            s.pop();
        }
        if(dp[m][n]==0){
            puts("KO"); // If there are no LCS
            exit(0);
        }
        return out;
    }
    static string All_LCS(vector<string> &arr){
        vector<string> res;
        for(auto i = 0; i < (int)arr.size(); ++i){
            for(auto j = i+1; j < (int)arr.size(); ++j){
                res.emplace_back(LCS(arr[i],arr[j]));
            }
        }
        return *min_element(res.begin(),res.end(),compare);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<string> arr;
    string s;
    int n; cin >> n;
    for(auto i = 0; i < n; i++){
        cin >> s;
        arr.emplace_back(s);
    }
    cout << Solution::All_LCS(arr) << "\n";
    return 0;
}
