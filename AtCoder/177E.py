# Coprime

import math

def GCD(arr)->int:
	gcd = arr[0]
	for i in range(1,len(arr)):
		gcd = math.gcd(arr[i],gcd)
	return gcd

def is_coprime(entry):
	for i in range(len(entry)-1):
		for j in range(i+1,len(entry)):
			if(GCD(entry)==1 and math.gcd(entry[i],entry[j])!=1):
				print("setwise", end="\n")
				return
			elif(GCD(entry)!=1 and math.gcd(entry[i],entry[j])!=1):
				print("neither", end="\n")
				return
			else:
				print("pairwise", end="\n")
				return
	 
if __name__=='__main__':
	tab1 = [3,4,5] #pairwise
	tab2 = [6,10,15] #setwise
	tab3 = [6,10,16] #neither
	is_coprime(tab1)
	is_coprime(tab2)
	is_coprime(tab3)
