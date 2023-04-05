"""
Given an array of size N and a number "c", determine whether or not there exist pairs of numbers "a" and "b", 
such that a+b=c. If there is an answer, return their indices.

Time Complexity: O(N)
Space Complexity: O(N)
"""

class Solution(object):
    def two_sum(self,arr:list,target:int):
        hashmap = {};
        for i, x in enumerate(arr):
            complement = target - x
            if complement in hashmap:
                return [hashmap[complement],i]
            hashmap[x] = i
        return None


if __name__=='__main__':
    test = [10,50,20,35,80,78]
    target = 60
    s = Solution()
    print(s.two_sum(test,target),end=" ")
