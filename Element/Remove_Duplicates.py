# Remove Duplicates from Sorted Array
# O(N) time complexity

def rem(arr)->int:
	lo = 0
	hi = lo+1
	while(lo < hi and hi < len(arr)):
		if(arr[lo]==arr[hi]):
			arr.remove(arr[lo])
			lo+=1
			hi+=1
		else:
			lo+=1
			hi+=1
	return len(arr)

if __name__=='__main__':
	arr = [1,1,2,2,3]
	print(rem(arr),end="\n") # 3
	
