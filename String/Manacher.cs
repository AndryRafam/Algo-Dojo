/*
Manacher algorithm: Find the longest palindromic substring in linear time complexity.

Time complexity: O(N), where N is the length of the string.
*/

using System;
using System.Collections.Generic;

class Solution{
    public static string manacher(string s){
        string s_prime = "";
        foreach(char x in s){
            s_prime+= x+"#";
        }
        s_prime = "#"+s_prime;
        int[] pal_radius = new int[s_prime.Length];
        Array.Fill(pal_radius,0);
        int center = 0;
        int right_bound = 0;
        int max_len = 0;
        int center_max_len = 0;
        for(int i = 0; i < s_prime.Length; ++i){
            if(i < right_bound){
                int mirror = 2*center-i;
                pal_radius[i] = Math.Min(right_bound-i,pal_radius[mirror]);
            }
            int l = i-(pal_radius[i]+1);
            int r = i+(pal_radius[i]+1);
            while(l >= 0 && r < s_prime.Length && s_prime[l]==s_prime[r]){
                pal_radius[i]++;
                l--;
                r++;
            }
            if(i+pal_radius[i] > right_bound){
                center = i;
                right_bound = i+pal_radius[i];
            }
            if(pal_radius[i] > max_len){
                max_len = pal_radius[i];
                center_max_len = i;
            }
        }
        int start = (center_max_len - max_len) >> 1;
        int end = start + max_len;
        string res = s.Substring(start,end-start);
        return res;
    }
    public static int Main(){
        string s = "abbacd";
        Console.Write(manacher(s));
        return 0;
    }
}
