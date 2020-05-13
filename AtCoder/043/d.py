from collections import Counter

def unbalanced(s:str)->bool:
    n = len(s)
    freq = Counter(s)
    for (key,val) in freq.items():
        if(val > n//2):
            return True
    return False


s = str(input())
n = len(s)
for i in range(n):
    for j in range(2,n+1-i):
        if(unbalanced(s[i:j])):
            print(s[i:j])
