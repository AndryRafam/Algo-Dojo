# 3 SUM problem

# Complexity: O(N²) if the array is already sorted
#             O(N²+NlogN) if the array is not sorted (we must sort the array first)

# In this example, the array is already sorted (O(N²) complexity


class Solution(object):
    def three_sum(self,arr:list,x:int):
        for i in range(len(arr)):
            self.l = i+1
            self.r = len(arr)-1
            self.flag = 0 # used to check if we have reached the end of the array
            while(self.l < self.r):
                if(arr[i]+arr[self.l]+arr[self.r]==x):
                    print(arr[i],arr[self.l],arr[self.r])
                    break;
                elif(arr[i]+arr[self.l]+arr[self.r] < x):
                    self.l+=1
                else:
                    self.r-=1
            self.flag+=1
            
        if(self.flag==len(arr)): # If we have reached the end of the array and no triplets was found
            print("NO TRIPLETS")
            

if __name__=='__main__':
    test = [10,20,35,50,78,80]
    target = 148
    s = Solution()
    s.three_sum(test,target) # 20 50 78
