# Affine Cipher Encrypt
# https://edabit.com/challenge/AQHcMKRr63ABCXNJo

# Here, we are gonna use ASCII standard

import math

def affineEncrypt(s:str,a:int,b:int)->str:
	if(math.gcd(a,26)!=1):
		return ""
	res = ""
	for x in s:
		res += chr((a*(ord(x)-97)+b)%26+97)
	return res

if __name__=='__main__':
	test = "itahari"
	a = 3
	b = 2
	print(affineEncrypt(test,a,b),end="\n") # ahcxcba
