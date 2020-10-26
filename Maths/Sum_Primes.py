# Sum of Prime Numbers
# https://edabit.com/challenge/GAbxxcsKoLGKtwjRB

import math

def is_prime(n:int)->bool:
	if (n < 2):
		return False
	if (n==2):
		return True
	for x in range(2,(int)(math.sqrt(n)+1)):
		if(n%x==0):
			return False
	return True

def sum_primes(arr:list)->int:
	sum = 0
	for i in arr:
		if(is_prime(i)):
			sum += i
	return sum


if __name__=='__main__':
	arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] # 17
	print(sum_primes(arr),end="\n")
