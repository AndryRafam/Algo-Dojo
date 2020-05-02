# Count the number of squares in N*N board
# O(N) complexity

class Solution(object):
    def count_square(self,n:int)->int:
        if(n==1):
            return 1
        self.num = 0
        for i in range(0,n):
            self.num += (n-i)*(n-i)
        return self.num


if __name__=='__main__':
    N = 64
    s = Solution()
    print(s.count_square(N)) # 89440
