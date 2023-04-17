/* Given string source and a dictionary of words words, return list of words[i] that is a subsequence of source.
O(K*M*N) complexity where K is the size of words array*/

using System;
using System.Collections.Generic;

class Solution{
    public static int LCS(string x, string y){
        int m = x.Length;
        int n = y.Length;
        int[,] dp = new int[m+1,n+1];
        for(int i = 0; i <= m; ++i){
            dp[i,0] = 0;
        }
        for(int j = 0; j <= n; ++j){
            dp[j,0] = 0;
        }
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(x[i-1]==y[j-1]){
                    dp[i,j] = dp[i-1,j-1]+1;
                }
                else{
                    dp[i,j] = Math.Max(dp[i-1,j],dp[i,j-1]);
                }
            }
        }
        return dp[m,n];
    }
    public static int Main(){
        string source = "bcogtadsjofisdhklasdej";
        List<string> words = new List<string> {"book","code","tag"};
        foreach(string word in words){
            if(LCS(source,word)==word.Length){
                Console.WriteLine(word);
            }
        }
        return 0;
    }
}
