# 2 Sum problem on a random array

# Complexity: O(N) if the array is already sorted
#             O(NlogN) if the array is not sorted (we must sort first sort the array)


# In this example, the array is not sorted (O(NlogN) complexity)

class Solution(object):
    def two_sum(self,arr:list,x:int):
        arr.sort()
        self.l = 0
        self.r = len(arr)-1
        self.flag = 0 # used to check if we have reached the end of the array
        while(self.l < self.r):
            if(arr[self.l]+arr[self.r]==x):
                print(arr[self.l],arr[self.r])
                return True
            elif(arr[self.l]+arr[self.r] < x):
                self.l+=1
            else:
                self.r-=1
        print("NO PAIRS")    

if __name__=='__main__':
    test = [10,50,20,35,80,78]
    target = 130
    s = Solution()
    s.two_sum(test,target)
