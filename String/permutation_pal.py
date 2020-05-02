# Check if any permutation of a string is a palindrome
# O(N) complexity

# Examples: civic -> True(palindrome itself)
#           ivicc -> True(permutation of civic which is a palindrome)
#            livic → False
#	     liciv → False


from collections import Counter

class Solution(object):
    def permut(self,s:str)->bool:
        self.odd_count = int()
        self.odd_count = 0
        self.dict = Counter(s)
        for (key,val) in self.dict.items():
            if(val%2!=0):
                self.odd_count+=1
        if(self.odd_count > 1):
            return False
        return True


if __name__=='__main__':
    test = "ivicc"
    s = Solution()
    print(s.permut(test)) # True
