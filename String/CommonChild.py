# Common Child problem from Hackerrank

def commonChild(s1,s2):
    m = len(s1)
    n = len(s2)
    dp = [[0 for j in range(n+1)] for i in range(m+1)]
    for i in range(m):
        for j in range(n):
            if(i==0 or j==0):
                dp[i][j]=0
            elif(s1[i-1]==s2[j-1]):
                dp[i+1][j+1]=dp[i][j]+1
            else:
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j])
    return dp[m][n]

if __name__=='__main__':
    s1 = "SHINCHAN"
    s2 = "NOHARAAA"
    print(commonChild(s1,s2))
