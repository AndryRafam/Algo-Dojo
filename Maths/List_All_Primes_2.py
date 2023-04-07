"""
Write a program that takes an integer argument and returns all prime numbers between 1 and the integer (included).

Sieve of eratosthenes approach.

Time complexity: O(Nlog(logN))
"""

def listAllPrimes(n:int)->list:
	primes = []
	is_prime = [True for i in range(n+1)]
	is_prime[0] = is_prime[1] = False
	
	for p in range(2,n+1):
		if is_prime[p]:
			primes.append(p)
		# sieve multiple of p
		for j in range(p,n+1,p):
			is_prime[j]=False
	return primes
	
if __name__=="__main__":
	n = int(input())
	print(listAllPrimes(n),end=" ")
