"""
You are given a string s and an integer k. Your task is to find the longest substring of s that contains at most 
k distinct characters. If there are multiple such substrings, return any one.

Write a function longest_substring_with_k_distinct_chars that takes a string s
and an integer k as input, and returns a string that is the longest substring of s
that contains at most k distinct characters.

Brute force approach
"""


from collections import Counter

def k_distinct (s:str, k:int)->bool:
    hashMap = Counter(s)

    if len(hashMap) <= k:
        return True
    
    return False

def longest_substring_k_distinct(s:str, k:int)->str:
    res = []
    temp = ""

    for i in range(len(s)):
        for j in range(i+1,len(s)+1):
            temp = s[i:j]
            if k_distinct(temp,k):
                res.append(temp)

    return max(res,key=len)


if __name__ == "__main__":
    k = int(input())
    s = input()
    print(longest_substring_k_distinct(s,k))