# CodeForce Problem 1183A

class Solution(object):
    def is_interesting(self,n:int)->bool:
        self.m = int()
        self.sum = 0
        while(n > 0):
            self.m = n%10
            self.sum = self.sum+self.m
            n//=10
        if(self.sum%4==0):
            return True
        return False


if __name__=='__main__':
    s = Solution()
    n = int(input())
    while(not s.is_interesting(n)):
        n+=1
    print(n)
