# Dutch Flag problem
# O(n) time complexity, O(1) space complexity

def dutch_flag(arr):
	lo = 0
	mid = 0
	hi = len(arr)-1
	while(mid <= hi):
		if arr[mid]==0:
			arr[lo],arr[mid] = arr[mid],arr[lo]
			lo+=1
			mid+=1
		elif arr[mid]==1:
			mid+=1
		else:
			arr[mid],arr[hi] = arr[hi],arr[mid]
			hi-=1
	return arr

if __name__=='__main__':
	arr = [0,1,2,2,1,0,0,2,0,1,1,0]
	dutch_flag(arr)
	for x in arr:
		print(x,end=" ")
	print("\n")
