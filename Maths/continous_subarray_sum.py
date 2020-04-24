class Solution(object):
    def __init__(self,nums,k:int):
        self.nums = nums
        self.k = k
    def answer(self,nums,k:int)->int:
        self.n = len(self.nums)
        for i in range(self.n):
            if(self.nums[i]%self.k==0):
                continue
            self.sum = self.nums[i]
            for j in range(i+1,self.n):
                self.sum = self.sum+self.nums[j]
                if(self.sum%self.k==0):
                    return True
        return False


if __name__=='__main__':
    arr = [23,2,6,4,7]
    k = 6
    s = Solution(arr,k)
    print(s.answer(arr,k)) # True
