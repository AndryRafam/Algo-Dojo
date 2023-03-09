"""Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.
Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".
Brute Force approach."""


from collections import Counter

def longestDupSubstr(s:str)->str:
    tab = []
    tab_res = []
    temp = ""
    for i in range(len(s)):
        for j in range(i+1,len(s)+1) :
            temp = s[i:j]
            tab.append(temp)
    hash = Counter(tab)
    for(key,val) in hash.items():
        if(val>=2):
            tab_res.append(key)
    str(tab_res)
    if(len(tab_res)==0):
        return ""
    return max(tab_res,key=len)


if __name__ == "__main__":
    s = input()
    print(longestDupSubstr(s))