# Climb stairs - O(N) time complexity && O(N) space complexity

def climbStairs(n):
	if(n==1):
		return 1
	dp = [None for i in range(n+1)]
	dp[1]=1
	dp[2]=2
	for i in range(3,n+1):
		dp[i]=dp[i-1]+dp[i-2]
	return dp[n]

if __name__=='__main__':
	n = 4
	print(climbStairs(n),end="\n") # 5
