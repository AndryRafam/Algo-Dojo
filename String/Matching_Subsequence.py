# Given string source and a dictionary of words words, return list of words[i] that is a subsequence of source.
# O(K*M*N) complexity where K is the size of words array

class Solution(object):
    def LCS(self,s1:str, s2:str)->int:
        self.m = len(s1)
        self.n = len(s2)
        self.dp = [[None]*(self.n+1) for i in range(self.m+1)]
        for i in range(self.m+1):
            for j in range(self.n+1):
                if(i==0 or j==0):
                    self.dp[i][j]=0
                elif(s1[i-1]==s2[j-1]):
                    self.dp[i][j]=self.dp[i-1][j-1]+1
                else:
                    self.dp[i][j]=max(self.dp[i-1][j],self.dp[i][j-1])
        return self.dp[self.m][self.n]


if __name__=='__main__':
    source = "bcogtadsjofisdhklasdej"
    words = ["book","code","tag"]
    s = Solution()
    for x in words:
        if(s.LCS(source,x)==len(x)):
            print(x, end=' ') # book, code
