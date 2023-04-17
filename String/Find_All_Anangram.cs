/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. 
You may return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

Time complexity: O(N) using sliding window techniques, where N is the length of s.
*/

using System;
using System.Collections.Generic;

class Solution{
    private static bool areEqualArray(int[] arr1, int[] arr2){
        if(arr1.Length!=arr2.Length){
            return false;
        }
        for(int i = 0; i < arr1.Length; ++i){
            if(arr1[i]!=arr2[i]){
                return false;
            }
        }
        return true;
    }
    public static List<int> findAnagrams(string s, string p){
        if(s.Length < p.Length){
            return new List<int>();
        }
        List<int> res = new List<int>();
        int[] hashS = new int[26];
        int[] hashP = new int[26];
        Array.Fill(hashS,0);
        Array.Fill(hashP,0);
        for(int i = 0; i < p.Length; ++i){
            hashS[s[i]-'a']++;
            hashP[p[i]-'a']++;
        }
        if(areEqualArray(hashS,hashP)){
            res.Add(0);
        }
        for(int i = p.Length; i < s.Length; ++i){
            hashS[s[i]-'a']++;
            hashS[s[i-p.Length]-'a']--;
            if(areEqualArray(hashS,hashP)){
                res.Add(i-p.Length+1);
            }
        }
        return res;
    }
    public static int Main(){
        string s = "oldmanemu";
        string p = "menu";
        foreach(int x in findAnagrams(s,p)){
            Console.WriteLine(x);
        }
        return 0;
    }
}
