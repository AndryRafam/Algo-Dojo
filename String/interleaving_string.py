# Interleaving string using LCS - O(M*N) complexity

def LCS(a:str, b:str)->bool:
    m = len(a)
    n = len(b)
    dp = [[None]*(n+1) for i in range(m+1)]
    for i in range(m+1):
        for j in range(n+1):
            if(i==0 or j==0):
                dp[i][j]=0
            elif(a[i-1]==b[j-1]):
                dp[i][j]=dp[i-1][j-1]+1
            else:
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])
    if(dp[m][n]==len(b)):
        return True
    return False


if __name__=='__main__':
    s1 = "aabcc"
    s2 = "dbbca"
    s3 = "aadbbcbcac"
    m = len(s1)
    n = len(s2)
    p = len(s3)
    if(LCS(s3,s1) and LCS(s3,s2) and p==m+n): # True
        print("True")
    else:
        print("False")
                
