/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.

Time complexity: O(MxN), where M is the size of s and N is the size of t.
*/

using System;
using System.Collections.Generic;

class Program{
    public static uint numDistinct(string s, string t){
        int m = s.Length;
        int n = t.Length;
        uint[,] dp = new uint[m+1,n+1];
        
        for(int i = 0; i <= s.Length; ++i){
            dp[i,0] = 1;
        }
        for(int i = 1; i <= s.Length; ++i){
            for(int j = 1; j <= t.Length; ++j){
                if(s[i-1] == t[j-1]){
                    dp[i,j] = dp[i-1,j-1]+dp[i-1,j];
                }
                else{
                    dp[i,j] = dp[i-1,j];
                }
            }
        }
        return dp[m,n];
    }
    public static int Main(){
        string s = "rabbbit";
        string t = "rabbit";
        Console.Write(numDistinct(s,t));
        return 0;
    }
}
