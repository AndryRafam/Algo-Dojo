"""
Given an array of integers that are out of order, determine the bounds of the smallest
window that must be sorted in order for the entire array to be sorted.
For example, given [ 3 , 7 , 5 , 6 , 9] , you should return ( 1 , 3 ).

Time complexity: O(N), where N is the size of the array
"""

def smallestWindow(arr):
	start = 0
	end = 0

	for i in range(len(arr)):
		if arr[i] > arr[i+1]:
			start = i
			break
	
	for j in range(start+1,len(arr)):
		max_so_far = max(arr[start],arr[j])
		if arr[j] < max_so_far:
			end = j
	
	return(start,end)
	
if __name__=="__main__":
	arr = [3 , 8 , 5 , 6 , 7] # (1,4)
	print(smallestWindow(arr),end=" ")
