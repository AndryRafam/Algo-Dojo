# AtCoder Beginner Contest (Problem 148)

import math

class Solution(object):
    def lcm(self,a:int,b:int)->int:
        return (a*b)//math.gcd(a,b)



if __name__=='__main__':
    a = 123
    b = 456
    s = Solution()
    print(s.lcm(a,b)) # 18696
