"""
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top ?
Time complexity && O(N) space complexity.
"""

def climbStairs(n):
	dp = [0 for i in range(n+1)]
	dp[0]=1
	for i in range(1,n+1):
		dp[i]=dp[i-1]+dp[i-2]
	return dp[n]

if __name__=="__main__":
	n = 12
	print(climbStairs(n),end="\n") # 233
