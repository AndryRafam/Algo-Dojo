# Given two unsorted arrays, find all pairs whose sum is equal to a given number
# O(N*M) complexity

class Solution(object):
    def find_pairs(self,arr1:list, arr2:list, k:int):
        for i in range(len(arr1)):
            for j in range(len(arr2)):
                if(arr1[i]+arr2[j]==k):
                    print(arr1[i],arr2[j])



if __name__=='__main__':
    arr1 = [1,2,3,7,5,4,8]
    arr2 = [0,7,4,3,2,1]
    k = 8
    s = Solution()
    s.find_pairs(arr1,arr2,k) # (1,7) (7,1) (5,3) (4,4) (8,0)
        
