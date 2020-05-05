# Rotational point in a dictionnary

class Solution(object):
    def rotation(self,arr:str):
        self.i = 0
        while(arr[self.i+1]>=arr[self.i]):
            self.i+=1
        print(arr[self.i+1])
        

if __name__=='__main__':
    s = Solution()
    arr = ["ptolemaic",
    "retrograde",
    "supplant",
    "undulate",
    "xenoepist",
    "asymptote",
    "babka",
    "banoffee",
    "engender",
    "karpatka",
    "othellolagkage"]
    s.rotation(arr)
