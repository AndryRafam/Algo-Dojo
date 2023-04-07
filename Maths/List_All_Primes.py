"""
Write a program that takes an integer argument and returns all prime numbers between 1 and the integer (included).

Brute force approach

Time complexity: O(N*sqrt(N))
"""

import math

def isPrime(n:int)->bool:
	if n==0 or n==1:
		return False
	for i in range(2,int(math.sqrt(n))+1):
		if n%i==0:
			return False
	return True
	
def listAllPrimes(n:int)->list:
	primes = []
	for k in range(0,n+1):
		if isPrime(k):
			primes.append(k)
	return primes
	
if __name__=="__main__":
	n = int(input())
	print(listAllPrimes(n),end=" ")
	
