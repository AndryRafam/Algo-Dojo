"""
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

Time complexity: O(N*2^N), where N is the length of the string S.
"""

class Solution:
    def partition(self,s:str):
        length = len(s)
        currentList = []
        result = []

        def dfs(start):
            if(start >= length):
                result.append(currentList.copy())
            for end in range(start,length):
                if self.isPalindrome(s,start,end):
                    currentList.append(s[start:end+1])
                    dfs(end+1)
                    currentList.pop()

        dfs(0)
        return result

    def isPalindrome(self,s:str,left:int,right:int)->bool:
        while(left < right):
            if(s[left]!=s[right]):
                return False
            left+=1
            right-=1
        return True

if __name__=="__main__":
    s = input()
    c = Solution()
    for x in c.partition(s):
        print(x, end=" ") 