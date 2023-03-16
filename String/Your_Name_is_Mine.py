"""
Problem

In an attempt to control the rise in population, Archer was asked to come up with a plan. This time he is targeting marriages. 
Archer, being as intelligent as he is, came up with the following plan:
A man with name M is allowed to marry a woman with name W, only if M is a subsequence of W or W is a subsequence of M.
A is said to be a subsequence of B, if A can be obtained by deleting some elements of B without changing the order 
of the remaining elements.
Your task is to determine whether a couple is allowed to marry or not, according to Archer's rule.

Input

The first line contains an integer T, the number of test cases. T test cases follow. Each test case contains two space separated 
strings M and W.

Output

For each test case print "YES" if they are allowed to marry, else print "NO". (quotes are meant for clarity, 
please don't print them)

Time complexity: O(n*m), where N is the length of M and m is the length of W. We are using LCS (Longest Common Subsequence)
algorithm here.
"""


def allow_marry(s:str, w:str):
    n = len(s)
    m = len(w)
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if s[i - 1] == w[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    return dp[n][m]

if __name__ == "__main__":
    t = int(input())

    for i in range(t):
        s,w = input().split()
        # if len LCS(s,w) is equal to s or to w, then the couple are allowed to marry.
        if allow_marry(s,w)==len(s) or allow_marry(s,w)==len(w):
            print("YES")
        else:
            print("NO")
    
	
