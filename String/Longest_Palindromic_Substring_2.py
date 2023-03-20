"""
Longest palindromic substring.

Given a string s, return the longest palindromic substring in s.

We are gonna solve this problem by expanding around the center of the string.

Time complexity: O(N²), where N is the length of the string.
"""

class Solution:
   def longestPalindrome(self,s:str)->str:
      s_prime = '#'+'#'.join(s)+'#'
      pal_radius = [0 for i in range(len(s_prime))]
      start = 0
      end = 0
      center = 0
      while(center < len(s_prime)):
         radius = 0
         while(center-(radius+1) >=0 and center+(radius+1) < len(s_prime) and s_prime[center-(radius+1)] == s_prime[center+(radius+1)]):
            radius+=1

         pal_radius[center] = radius
      
         if(pal_radius[center] > end-start):
            start = (center-radius)//2
            end = (center+radius)//2

         center+=1

      return s[start:end]
      

if __name__=="__main__":
   s = input()
   C = Solution()
   print(C.longestPalindrome(s))
