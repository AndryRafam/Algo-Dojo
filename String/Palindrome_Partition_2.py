"""
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

Dynamic programming approach.

Time complexity: O(N*2^N), where N is the length of the string S.
"""

class Solution:
    def partition(self,s:str):
        length = len(s)
        currentList = []
        dp = [[False for i in range(length)] for j in range(length)]
        result = []

        def dfs(start):
            if(start >= length):
                result.append(currentList.copy())
            for end in range(start,length):
                if(s[start]==s[end] and (end-start <=2 or dp[start+1][end-1])):
                    dp[start][end]=True
                    currentList.append(s[start:end+1])
                    dfs(end+1)
                    currentList.pop()

        dfs(0)
        return result

if __name__=="__main__":
    s = input()
    c = Solution()
    for x in c.partition(s):
        print(x, end=" ")