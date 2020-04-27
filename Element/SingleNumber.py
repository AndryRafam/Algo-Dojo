# Single numbers: Given 2*N+2 numbers, every numbers occurs twice except two of them.
# O(N) complexity

from collections import Counter

class Solution(object):
    def singleNumber(self,A:list)->list:
        self.res = []
        self.freqDict = Counter(A)
        for (self.key,self.val) in self.freqDict.items():
            if(self.val==1):
                self.res.append(self.key)
        return self.res

    
if __name__=='__main__':
    test = [1,2,2,3,4,4,5,3]
    s = Solution()
    print(s.singleNumber(test)) # [1,5]
