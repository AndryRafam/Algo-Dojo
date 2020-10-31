# Product of Two Prime Numbers
# https://edabit.com/challenge/LuC3AwFKJg2eEA4Kz

import math

def f(n:int)->bool:
	s = []
	x = 2
	while(x<=(int)(math.sqrt(n))):
		while(n%x==0):
			s.append(x)
			n/=x
		x+=1
	if(n>1):
		s.append(n)
	if(len(s)!=2):
		return False
	return True


if __name__=='__main__':
	n = 5767
	print(f(n),end="\n") # True
	
	
