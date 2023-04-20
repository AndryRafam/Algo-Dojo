"""
Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.

Time complexity: O(MxN), where M is the size of s and N is the size of t.
"""

def numDistinct(s:str,t:str)->int:
    m = len(s)
    n = len(t)
    dp = [[0]*(n+1) for i in range(m+1)]

    for i in range(m+1):
        dp[i][0] = 1

    for i in range(1,m+1):
        for j in range(1,n+1):
            if s[i-1]==t[j-1]:
                dp[i][j] = dp[i-1][j-1]+dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j]

    return dp[m][n]

if __name__=="__main__":
    s = "rabbbit"
    t = "rabbit"
    print(numDistinct(s,t),end=" ")