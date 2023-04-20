# Kadane's algo - O(N) complexity

from typing import List

def kadane(arr:List)->int:
    currSum = arr[0]
    maxSum = arr[0]

    for i in range(1,len(arr)):
        currSum = max(arr[i],currSum+arr[i])
        maxSum = max(currSum,maxSum)
    
    return maxSum

if __name__=="__main__":
    arr = [-1,2,4,-3,5,2,-5,2]
    print(kadane(arr),end=" ")
