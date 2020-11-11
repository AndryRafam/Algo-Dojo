# Count prime numbers
# https://edabit.com/challenge/Ba4vZuzC7b2Zr6SPs

import math

def is_prime(n:int)->bool:
	if(n==2):
		return True
	i=2
	while(i<=(int)(math.sqrt(n))):
		if(n%i==0):
			return False
		i+=1
	return True

def primeNumber(n:int)->int:
	ct=0
	for x in range(2,n+1):
		if(is_prime(x)):
			ct+=1
	return ct


if __name__=='__main__':
	n = 30
	print(primeNumber(n),end="\n") # 10


