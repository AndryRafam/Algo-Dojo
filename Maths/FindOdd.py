# Find the Odd Integer
# https://edabit.com/challenge/wgnmQTbfssuhvZHqe

from collections import Counter

def findOdd(arr:list):
	h = Counter(arr)
	for (key,val) in h.items():
		if(val%2!=0):
			print(key,end="\n")
	return

if __name__=='__main__':
	test = [20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5]
	findOdd(test)
