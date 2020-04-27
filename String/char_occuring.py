# Occuring number of character within a string - O(N) complexity

from collections import Counter

class Solution(object):
    def occur(self,s:str,c:chr)->int:
        self.freqDict = Counter(s)
        for (self.key,self.val) in self.freqDict.items():
            if(self.key == c):
                return self.val

        return 0 # if there is no character equal to c

if __name__=='__main__':
    test = "agoraphobia"
    s = Solution()
    print(s.occur(test,"a")) # 3
