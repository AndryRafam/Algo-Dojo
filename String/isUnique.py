from collections import Counter # creating a dictionary

class Solution(object):
    def __init__(self,s:str):
        self.s = s
    def isUnique(self,s:str)->bool:
        self.freqDict = Counter(self.s)
        for (self.key,self.val) in self.freqDict.items():
            if(self.val > 1):
                return True
        return False

    
if __name__=='__main__':
    string1 = "hello"
    string2 = "salute"
    s1 = Solution(string1)
    s2 = Solution(string2)

    print(s1.isUnique(string1)) # True
    print(s2.isUnique(string2)) # False
