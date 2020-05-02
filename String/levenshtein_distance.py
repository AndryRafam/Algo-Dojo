# Levenshtein distance

def lev_dist(a:str, b:str)->int:
    m = len(a)
    n = len(b)
    d = [[None]*(n+1) for i in range(m+1)]

    for i in range(m+1):
        for j in range(n+1):
            if(i == 0):
                d[i][j]=j
            elif(j == 0):
                d[i][j]=i
            elif(a[i-1] == b[j-1]):
                d[i][j] = d[i-1][j-1]
            else:
                d[i][j] = min(min(1 + d[i-1][j], 1 +d[i][j-1]), 1 + d[i-1][j-1])
    return d[m][n]


if __name__=='__main__':
    a = "algorithm"
    b = "algebraic"
    print(lev_dist(a,b)) # 6
