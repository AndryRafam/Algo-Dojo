/*
Longest palindromic substring.
Given a string s, return the longest palindromic substring in s.
We are gonna solve this problem by expanding around the center of the string.

Time complexity: O(N²), where N is the length of the string.
*/

using System;

public class Solution{
    public static string longestPalindrome(string s){
        string s_prime = "";
        foreach(char c in s){
            s_prime += c+"#";
        }
        s_prime = "#"+s_prime;
        int start = 0;
        int end = 0;
        int center = 0;
        while(center < s_prime.Length){
            int radius = 0;
            while(center-(radius+1) >= 0 && center+(radius+1) < s_prime.Length && s_prime[center-(radius+1)]==s_prime[center+(radius+1)]){
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
