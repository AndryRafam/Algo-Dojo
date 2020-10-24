# Most frequent word in array.
# If there is a tie, print any.

from collections import Counter

def freq(vec):
	hash = Counter(vec)
	max = 0
	s = ""	
	for (key,val) in hash.items():
		if(max < val):
			max = val
			s = key
	print(s,end="\n")
	
if __name__=='__main__':
		vec = ["jones","paul","jones","peter","jones","peter","jackson","peter"]
		freq(vec)
			
