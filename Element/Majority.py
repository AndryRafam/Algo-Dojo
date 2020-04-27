# Find the majority element - O(N) complexity

from collections import Counter

class Solution(object):
    def majority(self,tab:list)->int:
        self.freqDict = Counter(tab)
        for (self.key,self.val) in self.freqDict.items():
            if(self.val > len(tab)/2):
                return self.key
        return -1


if __name__=='__main__':
    test1 = [1,2,5,9,5,5,5]
    test2 = [1,5,3,2,2,4,7,8,9,8,9]
    s = Solution()
    print(s.majority(test1)) # 5
    print(s.majority(test2)) # -1
