# CodeForce problem 71A

import sys

def too_long(s:str):
    n = len(s)
    if(n<=10):
        print(s)
    else:
        print(s[0]+str(n-2)+s[n-1])

        
if __name__=='__main__':
    n = int(input())
    s = str()
    for i in range(n):
        s = input()
        too_long(s)
    
