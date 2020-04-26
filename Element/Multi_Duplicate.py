from collections import Counter

class Solution(object):
    def __init__(self,tab):
        self.tab = tab
    def multi_duplicate(self,tab):
        self.freqDict = Counter(self.tab)
        for (self.key,self.val) in self.freqDict.items():
            if(self.val > 1):
                print(self.key, "->", self.val)
                

if __name__=='__main__':
    test = [1,2,5,3,6,3,5]
    s = Solution(test)
    s.multi_duplicate(test)
                    
