class Solution(object):
    def __init__(self,tab):
        self.tab = tab
    def count_subgrid(self,tab)->int:
        self.subgrids = 0
        self.n = len(tab)
        for x in range(self.n):
            for y in range(x+1,self.n):
                self.count = 0
                for i in range(self.n):
                    if((self.tab[x][i]==1)and(self.tab[y][i]==1)):
                        self.count+=1
                self.subgrids += ((self.count-1)*self.count)/2
        return self.subgrids

    

if __name__=='__main__':
    tab = [[0,1,0,0,1],
           [0,1,1,0,0],
           [1,0,0,0,0],
           [0,1,1,0,1],
           [0,0,0,0,0]]
    s = Solution(tab)
    print(s.count_subgrid(tab))
