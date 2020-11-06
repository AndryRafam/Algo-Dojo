# 3 Divisors
# Given a value N. The task is to find how many numbers less than or equal 
# to N have numbers of divisors exactly equal to 3.

def three_div(N:int)->bool:
	div = 0
	for x in range(1,N+1):
		if(N%x==0):
			div+=1
	f = True if(div==3) else False
	return f

if __name__=='__main__':
	N = 30
	ct = 0
	for x in range(1,N+1):
		if(three_div(x)):
			ct+=1
	print(ct,end="\n") # 3

