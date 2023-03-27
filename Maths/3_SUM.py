"""
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Time complexity: O(NlogN)+O(N²)*O(logN) = O(N²logN+NlogN), sort the array first and then apply two pointers approach.
N is the size of the array.
"""

def threeSum(nums):
    nums.sort()
    result = set()
    for i in range(len(nums)):
        j = i+1
        k = len(nums)-1
        while (j < k):
            if nums[i]+nums[j]+nums[k]==0:
                result.add((nums[i],nums[j],nums[k]))
                k-=1
                j+=1
            elif nums[i]+nums[j]+nums[k] < 0:
                j+=1
            else:
                k-=1
    return result

if __name__=="__main__":
    test = [-1,0,1,2,-1,-4]
    print(threeSum(test),end=" ")
