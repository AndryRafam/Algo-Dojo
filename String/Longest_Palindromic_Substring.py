# Longest palindromci substring - O(N²) complexity


class Solution(object):
    def isPalindrome(self,s:str)->bool:
        self.rev = str()
        self.rev = reversed(s)
        return list(s) == list(self.rev)


    def longest_palindrome(self,s:str)->str:
        self.arr = []
        self.temp = str()
        self.temp = ""
        for i in range(len(s)):
            for j in range(1,len(s)+1-i):
                self.temp = s[i:j]
                if(self.isPalindrome(self.temp)):
                    self.arr.append(self.temp)
        return max(self.arr)


if __name__=='__main__':
    test = "xoxoxbab"
    s = Solution()
    print(s.longest_palindrome(test))
