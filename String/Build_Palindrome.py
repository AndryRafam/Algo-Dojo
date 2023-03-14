"""Given two string 'a' and 'b'; find a string 's' such that:

1) s = sa + sb, where 'sa' and 'sb' are non empty substring of 'a' and 'b'.

2) s is a palindromic string.

3) the length of is as long as possible

If there are multiple answer, return the one who comes first alaphabetically. If there is no answer, return -1.

Brute force approach."""


def is_palindrome(s:str)->bool:
    n = len(s)
    l = 0
    r = n-1
    while l < r:
        if s[l]!=s[r]:
            return False
        l+=1
        r-=1
    return True

def build_palindrome(a:str, b:str)->str:
    a_tab = []
    b_tab = []
    pal_tab = [] # list to store all built palindrome

    for i in range(len(a)):
        for j in range(i+1,len(a)+1):
            a_tab.append(a[i:j])

    for k in range(len(b)):
        for l in range(k+1,len(b)+1):
            b_tab.append(b[k:l])

    for x in a_tab:
        for y in b_tab:
            if is_palindrome(x+y):
                pal_tab.append(x+y)
    
    if len(pal_tab)==0:
        return "-1"

    maxlen = 0
    candidate = ""

    for s in pal_tab:
        if maxlen < len(s):
            maxlen = len(s)
            candidate = s
        elif maxlen==len(s) and s < candidate:
            candidate = s
    
    return candidate

if __name__ == "__main__":
    q = int(input()) # number of queries
    for i in range(q):
        a = input()
        b = input()
        print(build_palindrome(a,b))


    