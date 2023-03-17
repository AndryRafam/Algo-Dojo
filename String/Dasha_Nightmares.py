"""
Codeforces problem 1800F.

Time complexity: O(N²k), where N is the size the number of strings and k in the length of the longest string.
"""

from collections import Counter

def is_nightmare(a:str,b:str)->bool:
    t = a+b
    if(len(t)%2==0):
        return False
    occur = set()
    for i in range(len(t)):
        occur.add(t[i])
    if(len(occur)!=25):
        return False
    freq = Counter(t)
    for(key,val) in freq.items():
        if(val%2==0):
            return False
    return True

def count_pairs(words:list)->int:
    count = 0
    for i in range(len(words)-1):
        for j in range(i+1,len(words)):
            if(is_nightmare(words[i],words[j])):
                count+=1
    return count

if __name__=="__main__":
    n = int(input())
    count = 0
    words = []
    for i in range(n):
        s = input()
        words.append(s)
    print(count_pairs(words))
