#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static void CommonFactor(string &s1, string &s2){
        int m = s1.length();
        int n = s2.length();
        int row, col;
        int len = 0;
        int CF[m+1][n+1];

        for(auto i = 0; i <= m; ++i){
            for(auto j = 0; j <= n; ++j){
                if(i==0 || j==0)
                    CF[i][j]=0;
                else if(s1[i-1]==s2[j-1]){
                    CF[i][j]=CF[i-1][j-1]+1;
                    if(len < CF[i][j]){
                        len = CF[i][j];
                        row = i;
                        col = j;
                    }
                }
                else
                    CF[i][j]=0;
            }
        }
        if(len==0){
            cout << "NO FACTOR" << "\n"; return;}
        stack<char> s;
        while(CF[row][col]!=0){
            s.push(s1[row-1]); row--; col--;}
        while(!s.empty()){
            cout << s.top(); s.pop();
        }
        cout <<"\n";
        return;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    string s1, s2;
    for(auto i = 0; i < N; ++i){
        cin >> s1 >> s2;
        Solution::CommonFactor(s1,s2);
    }
    return 0;
}
