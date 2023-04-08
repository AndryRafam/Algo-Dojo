"""
Given an integer g >= 2, an integer m > 2 and an integer n >= m;
return the first pair of prime numbers between m and n, that has a gap of size g.
If there is no such prime numbers, return null.

Time complexity: O((N-M)log(log(N-M))) + O(K²), where K is the number of prime numbers between m and n.
"""

class Solution:
	def gap(self, g:int, m:int, n:int)->list:
		primes = []
		is_prime = [True for _ in range(n+1)]
		is_prime[0] = is_prime[1] = False
	
		for p in range(m,n+1):
			if is_prime[p]:
				primes.append(p)
			for j in range(p,n+1,p):
				is_prime[j] = False
		
		res = []
		for i in range(len(primes)):
			for j in range(i+1,len(primes)):
				if primes[j]-primes[i]==g:
					res.append(primes[i])
					res.append(primes[j])
					return res
		return [0,0]
	

if __name__ == "__main__":
	g = int(input())
	m = int(input())
	n = int(input())
	
	S = Solution()
	print(S.gap(g,m,n),end=" ")
