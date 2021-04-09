# Source: https://edabit.com/challenge/ShunivMZuPRgEg7iQ

import math

def prime(n)->bool:
    if(n < 2):
        return False
    for x in range(2,int(math.sqrt(n))+1):
        if(n%x==0):
            return False
    return True

def prime_gaps(g,a,b):
    t = []
    for i in range(a,b+1):
        if(prime(i)):
            t.append(i)
    for x in range(len(t)):
        for y in range(x+1,len(t)):
            if(t[y]-t[x]==g):
                print(t[x],end=" ")
                print(t[y],end="\n")
                return
    print(0,end=" ")
    print(0,end="\n")
    return

if __name__=="__main__":
    g = 4
    a = 130
    b = 200
    prime_gaps(g,a,b) # 163 167