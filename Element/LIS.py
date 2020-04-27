# Longest Increasing Subsequence DP - O(N²) complexity

class Solution(object):
    def LIS(self,arr)->int:
        self.n = len(arr)
        self.DP = [None for i in range(self.n)]
        for i in range(self.n):
            self.DP[i] = 1
            for j in range(i):
                if(arr[j] < arr[i]):
                    self.DP[i] = max(self.DP[i],self.DP[j]+1)
        return max(self.DP)


if __name__=='__main__':
    test = [1,7,3,5,9,4,8]
    s = Solution()
    print(s.LIS(test)) # 4 (1,3,5,8)
