"""
You are given an array of integers arr and an integer k. Your task is to find the maximum sum of a non-empty
subarray of length at most k. The subarray should contain at least one element.
Write a function max_sum_subarray that takes the array arr and the integer k as input and returns
the maximum sum of a subarray of length at most k.

Time complexity: O(N), where N is the size of the array
"""

def maxSubarraySum_k(arr,k)->int:
    window_sum = 0 # sum of the window of length k
    max_sum = 0

    for i in range(k):
        window_sum += arr[i]
    
    for i in range(k,len(arr)):
        window_sum += arr[i] - arr[i-k]
        max_sum = max(window_sum,max_sum)
    
    return max_sum

if __name__=="__main__":
    arr = [1, 4, 2, 10, 2, 3, 1, 0, 20]
    k = 4
    print(maxSubarraySum_k(arr,k),end=" ")