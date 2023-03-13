"""Let's define a function countUniqueChars(s) that returns the number of unique characters on s.

For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.

Given a string s, return the sum of countUniqueChars(t) where t is a substring of s. The test cases are generated such that the answer fits in a 32-bit integer.

Notice that some substrings can be repeated so in this case you have to count the repeated ones too.

Brute force approach: O(N³) time complexity, where N is the size of the string.

It takes O(N²) to generate all substrings of the string, and O(N) to count the number of unique characters."""

from collections import Counter

def uniqueLetterString (s:str)->int:
    mp = Counter(s)
    count = 0
    
    for (key,val) in mp.items():
        if(val > 1):
            continue
        else:
            count+=1
    return count

if __name__=="__main__":
    s = input()
    total_count = 0
    for i in range(len(s)):
        for j in range(i+1,len(s)+1):
            temp = s[i:j]
            total_count+=uniqueLetterString(temp)
    
    print(total_count)