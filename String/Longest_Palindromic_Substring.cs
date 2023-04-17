/*
Given a string s, find the length of the longest substring without repeating characters.

Let N, the length of the input string.

Solution 1: Brute force approach - Time complexity: O(N³).

Solution 2: Sliding window approach - Time complexity: O(N). 
*/

using System;
using System.Collections.Generic;

class Solution_1{
    public int lengthOfLongestSubstrNoRepeat(string s){
        int max_len = 0;
        int l = 1;
        while(l < s.Length){
            for(int i = 0; i <= s.Length-l; ++i){
                string temp = s.Substring(i,l);
                if(isUnique(temp)){
                    max_len = temp.Length;
                }
            }
        }
        return max_len;
    }
    private static bool isUnique(string a){
        HashSet<char> hash = new HashSet<char>();
        foreach(char x in a){
            hash.Add(x);
        }
        if(hash.Count==a.Length){
            return true;
        }
        return false;
    }
}

class Solution_2{
    public int lengthOfLongestSubstrNoRepeat(string s){
        HashSet<char> hashSet = new HashSet<char>();
        int l = 0;
        int r = 0;
        int max_len = 0;
        while(r < s.Length){
            if(!hashSet.Contains(s[r])){
                hashSet.Add(s[r]);
                max_len = Math.Max(max_len,r-l+1);
                r++;
            }
            else{
                hashSet.Remove(s[l]);
                l++;
            }
        }
        return max_len;
    }
}

class Driver{
    public static int Main(){
        Solution_2 s2 = new Solution_2();
        string x = "abcabcbb";
        Console.Write(s2.lengthOfLongestSubstrNoRepeat(x));
        return 0;
    }
}
