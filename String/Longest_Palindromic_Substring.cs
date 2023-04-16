/*Longest palindromic substring.
Given a string s, return the longest palindromic substring in s.
Brute force approach.

Time complexity: O(N³), where N is the length of the string.*/

using System;

public class Solution{
    public static string longestPalindrome(string s){
        int max_len = 0;
        string longest_pal = "";
        for(int i = 0; i < s.Length; ++i){
            for(int j = 1; j <= s.Length-i; ++j){
                string temp = s.Substring(i,j);
                if(isPalindrome(temp) && max_len < temp.Length){
                    longest_pal = temp;
                    max_len = temp.Length;
                }
            }
        }
        return longest_pal;
    }
    private static bool isPalindrome(string s){
        int l = 0;
        int r = s.Length-1;
        while(l < r){
            if(s[l++]!=s[r--]){
                return false;
            }
        }
        return true;
    }
    public static int Main(){
        string test = "abbac";
        Console.Write(longestPalindrome(test));
        return 0;
    }
}
