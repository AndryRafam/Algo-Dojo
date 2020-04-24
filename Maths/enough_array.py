class Solution(object):
    def __init__(self,nums,k:int):
        self.nums = nums
        self.k = k
    def answer(self,nums,k:int)->int:
        self.count = 0
        self.n = len(self.nums)
        for i in range(self.n):
            if(self.nums[i]>=k):
                self.count+=1
            self.sum = self.nums[i]
            for j in range(i+1,self.n):
                self.sum = self.sum + self.nums[j]
                if(self.sum>=k):
                    self.count+=1
        return self.count


if __name__=='__main__':
    arr = [103, 35322, 232, 342, 21099, 90000, 18843, 9010, 35221, 19352]
    k = 53462
    s = Solution(arr,k)
    print(s.answer(arr,k))
