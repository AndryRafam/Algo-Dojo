"""
Given an integer g >= 2, an integer m > 2 and an integer n >= m;
return the first pair of prime numbers between m and n, that has a gap of size g.
If there is no such prime numbers, return null.

Brute force approach

Time complexity: O((N-M)²)*O(Ksqrt(K)) = O((N-M)²Ksqrt(K))
"""

import math

def isPrime(n)->bool:
    if(n < 2):
        return False
    for x in range(2,int(math.sqrt(n))+1):
        if(n%x==0):
            return False
    return True

def prime_gaps(g,m,n)->list:
	res = []
	for i in range(m,n+1):
		for j in range(i+1,n+1):
			if isPrime(i) and isPrime(j) and j-i==g:
				res.append(i)
				res.append(j)
				return res
	return [0,0] 
		

if __name__=="__main__":
    g = int(input())
    m = int(input())
    n = int(input())
    print(prime_gaps(g,m,n),end=" ")
