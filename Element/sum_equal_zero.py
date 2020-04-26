class Solution(object):
    def __init__(self,arr):
        self.arr = arr
    def sum_zero(self,arr)->bool:
        self.n = len(self.arr)
        for i in range(self.n):
            self.sum = 0
            for j in range(i+1,self.n):
                self.sum += self.arr[j]
                if(self.sum == 0):
                    return True
        return False
    

if __name__=='__main__':
    test = [4,2,-3,1,6]
    s = Solution(test)
    print(s.sum_zero(test)) # True (2,-3,1)
