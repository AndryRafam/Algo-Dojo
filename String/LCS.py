class Solution(object):
    def LCS(self,s1:str,s2:str)->int:
        self.m = len(s1)
        self.n = len(s2)
        self.DP = [[None]*(self.n+1) for i in range(self.m+1)]

        for i in range(self.m+1):
            for j in range(self.n+1):
                if(i==0 or j==0):
                    self.DP[i][j] = 0
                elif(s1[i-1]==s2[j-1]):
                    self.DP[i][j] = self.DP[i-1][j-1]+1
                else:
                    self.DP[i][j] = max(self.DP[i-1][j],self.DP[i][j-1])
        return self.DP[self.m][self.n]

    
if __name__=='__main__':
    text1 = "GeekforGeek"
    text2 = "Geek"
    s = Solution()
    print(s.LCS(text1,text2))
