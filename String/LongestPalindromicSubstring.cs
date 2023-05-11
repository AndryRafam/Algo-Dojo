/*
Longest palindromic substring.

Expand around the center: O(N²) time complexity.
*/

using System;

public class Solution{
    public static string longestPalindrome(string s){
        string s_prime = "#";
        foreach(char c in s){
            s_prime += c+"#";
        }
        int start = 0;
        int end = 0;
        int center = 0;
        while(center < s_prime.Length){
            int radius = 0;
            int l = center-(radius+1);
            int r = center+(radius+1);
            while(l >= 0 && r < s_prime.Length && s_prime[l--]==s_prime[r++]){
                radius++;
            }
            if(radius > end-start){
                start = (center-radius) >> 1;
                end = (center+radius) >> 1;
            }
            center++;
        }
        string res = s.Substring(start,end-start);
        return res;
    }
    public static int Main(){
        string test = "abba";
        Console.Write(longestPalindrome(test));
        return 0;
    }
}
