# Longest palindromci substring - O(N³) complexity

class Solution:
    def longestPalindrome(self,s:str)->str:
        maxi = 0
        longest_pal = ""

        def isPalindrome(s:str)->bool:
            l = 0
            r = len(s)-1
            while l < r:
                if s[l]!=s[r]:
                    return False
                l+=1
                r-=1
            return True

        for i in range(len(s)):
            for j in range(i+1,len(s)+1):
                temp = s[i:j]
                if isPalindrome(temp) and maxi < len(temp):
                    maxi = len(temp) 
                    longest_pal = temp 
        
        return longest_pal


if __name__=="__main__":
    test = "xoxoxbaobab"
    s = Solution()
    print(s.longestPalindrome(test),end=" ")
