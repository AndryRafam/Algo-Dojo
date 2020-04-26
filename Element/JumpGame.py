class Solution(object):
    def __init__(self,arr):
        self.arr = arr
    def isReachable(self,arr)->bool:
        self.n = len(self.arr)
        if(self.n<=1):
            return True
        self.maxReach = 0
        self.step = 1
        for i in range(self.n):
            self.step -= 1
            if(i+self.arr[i] > self.maxReach):
                self.maxReach = i+self.arr[i]
                self.step = self.arr[i]
            if(self.step == 0 and i < self.n-1):
                return False
        return True
    

if __name__=='__main__':
    test1 = [2,3,1,1,4]
    test2 = [3,2,1,0,4]
    s1 = Solution(test1)
    s2 = Solution(test2)
    print(s1.isReachable(test1)) # True
    print(s2.isReachable(test2)) # False
