# Word break in O(N²) complexity

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
    return dp[m][n]


if __name__=='__main__':
    s = "lintcode"
    dico = list()
    dico = ["lint","code"]
    for x in range(len(dico)):
        res = str()
        res = dico[x]
        for y in range(x+1,len(dico)):
            res+=dico[y]
            if(LCS(s,dico[x]) and LCS(s,dico[y]) and len(res)==len(s)):
                print("True")
                exit(0)
    print("False")
