# Equalize array: Determine the minimum number of elements to delete, such that the remaining elements are all equals.
# Example: [1,2,2,3] → [2,2] 
# Complexity: O(N), N is the size of the array

from collections import Counter

def min_equal(arr):
	temp = 0
	hash = Counter(arr)
	for (key,val) in hash.items():
		if(temp < val):
			temp = val
	return len(arr)-temp

if __name__=='__main__':
	arr = [3,3,2,1,3]
	print(min_equal(arr),end="\n")
