# Kadane's algo - O(N) complexity

class Solution(object):
    def kadane(self,arr:list)->int:
        self.best = 0
        self.sum = 0
        self.n = len(arr)
        for i in range(self.n):
            self.sum = max(arr[i],self.sum+arr[i])
            self.best = max(self.best,self.sum)
        return self.best
    

if __name__=='__main__':
    test = [-1,2,4,-3,5,2,-5,2]
    s = Solution()
    print(s.kadane(test)) # 10 [2,4,-3,5,2]
