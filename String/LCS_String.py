# Longest Common Substring DP (Dynamic Programming)
# O(M*N) complexity

class Solution(object):
    def LCSS(self,s1:str,s2:str)->int:
        self.m = len(s1)
        self.n = len(s2)
        self.result = 0
        self.DP = [[None]*(self.n+1) for i in range(self.m+1)]

        for i in range(self.m+1):
            for j in range(self.n+1):
                if(i== 0 or j == 0):
                    self.DP[i][j] = 0
                elif(s1[i-1]==s2[j-1]):
                    self.DP[i][j] = self.DP[i-1][j-1]+1
                    self.result = max(self.result,self.DP[i][j])
                else:
                    self.DP[i][j]=0
        return self.result


if __name__=='__main__':
    text1 = "OldGame: Assassin's Creed"
    text2 = "NewGame: Assassin's Creed Odyssey"
    s = Solution()
    print(s.LCSS(text1,text2)) # 22
