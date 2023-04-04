"""
Climb stairs with at most k steps. (k > 0)
Time complexity: O(n*k), where n is the number of staircases and k is the maximum step allowed.
"""

def climbStairs_k(n:int,k:int)->int:
	dp = [0 for x in range(n+1)]
	dp[0] = 1
	for i in range(1,n+1):
		for j in range(1,k+1):
			if i-j >= 0:
				dp[i] += dp[i-j]
	return dp[n]
	
if __name__=="__main__":
	n = 12
	k = 5
	print(climbStairs_k(n,k),end=" ") # 1793
