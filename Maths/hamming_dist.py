class Solution(object):
    def __init__(self,s1:str,s2:str):
        self.s1 = s1
        self.s2 = s2
    def hamming_dist(self,s1:str,s2:str)->int:
        if(len(self.s1)!=len(self.s2)):
            return False
        self.count = 0
        for x in range(len(self.s1)):
            if(self.s1[x]!=self.s2[x]):
                self.count+=1
        return self.count

    

if __name__=='__main__':
    s1 = "01101"
    s2 = "11010"
    s = Solution(s1,s2)
    print(s.hamming_dist(s1,s2)) # 4
