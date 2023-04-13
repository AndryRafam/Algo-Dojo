"""
Given an array of integers, find the length of the longest increasing subarray.
An increasing subarray is a contiguous subarray in which the elements are in strictly increasing order.

Time complexity: O(N), N is the size of the array.
"""

def longestIncreasingSubArray(arr:list)->int:
    if not arr:
        return {}
    current_len = 1
    max_len = 1
    for i in range(1,len(arr)):
        if arr[i] > arr[i-1]:
            current_len += 1
        else:
            max_len = max(current_len,max_len)
            current_len = 1
    return max(max_len,current_len)

if __name__=="__main__":
    arr = [1, 2, 3, 1, 2, 3, 4, 1]
    print(longestIncreasingSubArray(arr),end=" ")