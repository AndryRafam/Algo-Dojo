class Solution(object):
    def __init__(self,nums,k:int):
        self.nums = nums
        self.k = k
    def subarraySum(self,nums,k:int)->int:
        self.count = 0
        self.n = len(self.nums)
        for i in range(self.n):
            if(self.nums[i]==self.k):
                self.count+=1
            self.sum = self.nums[i]
            for j in range(i+1,self.n):
                self.sum = self.sum+self.nums[j]
                if(self.sum==self.k):
                    self.count+=1
        return self.count


if __name__=='__main__':
    test = [1,1,1]
    k = 2
    s = Solution(test,k)
    print(s.subarraySum(test,k)) # 2
