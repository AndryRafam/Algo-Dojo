# AtCoder Dwango Programming Contest (Problem A)

class Solution(object):
    def music(self,s_arr:list,k_arr:list, X:str, N:int)->int:
        self.count = 0
        for i in range(N):
            if(s_arr[i]==X):
                for j in range(i+1,N):
                    self.count+=k_arr[j]
        return self.count


if __name__=='__main__': # test program
    N = 3
    s_arr = ['dwango','sixth','roll']
    k_arr = [2,5,25]
    X = 'dwango'
    s = Solution()
    print(s.music(s_arr,k_arr,X,N)) # 30
