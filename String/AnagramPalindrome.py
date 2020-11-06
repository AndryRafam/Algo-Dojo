# Anagram Palindrome
# Given a string S, Check if characters of the given string 
# can be rearranged to form a palindrome. 

from collections import Counter

def check(s:str)->bool:
    h = Counter(s)
    c = 0
    for (key,val) in h.items():
        if(val==1):
            c+=1
    res = "YES" if(c==1) else "NO"
    return res


if __name__=='__main__':
    s1 = "geeksogeeks"
    s2  = "geeksforgeeks"
    print(check(s1),end="\n") # YES
    print(check(s2),end="\n") # NO