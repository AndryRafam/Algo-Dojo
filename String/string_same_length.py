# AtCoder Beginner Contest 148 (Task B)

class Solution(object):
    def str(self,s1:str,s2:str)->str:
        self.res = ''
        if(len(s1)!=len(s2)):
            return -1
        for i in range(len(s1)):
            self.res += s1[i]
            self.res += s2[i]
        return self.res



if __name__=='__main__':
    s1 = "ip"
    s2 = "cc"
    s = Solution()
    print(s.str(s1,s2)) # icpc
