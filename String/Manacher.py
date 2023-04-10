"""
Manacher algorithm: Find the longest palindromic substring in linear time complexity.

Time complexity: O(N), where N is the length of the string.
"""

class Solution:
    def manacher(self,s:str)->str:
        s_process = '#'+'#'.join(s)+'#' # add bogus to the string, so that we can handle both odd and even length
        pal_radius = [0 for _ in range(len(s_process))]
        center = 0
        max_right = 0 # the index of the right boundary of the longest palindrome
        max_len = 0 # the length of the longest palindrome found so far
        max_len_center = 0 # the index of the center of the longest palindrome found so far

        for i in range(len(s_process)):
            if i < max_right:
                mirror = 2*center-i
                pal_radius[i] = min(max_right - i, pal_radius[mirror])
            
            # attempt to expand around the current center i
            left = i - (pal_radius[i]+1)
            right = i + (pal_radius[i]+1)

            while(left >= 0 and right < len(s_process) and s_process[left]==s_process[right]):
                pal_radius[i]+=1
                left-=1
                right+=1
            
            # check if the palindrome centered at i extends beyond the right boundary
            if i+pal_radius[i] > max_right:
                center = i
                max_right = i+pal_radius[i]

            # update the longest palindrome found so far
            if pal_radius[i] > max_len:
                max_len = pal_radius[i]
                max_len_center = i

        # extract the longest palindromic substring
        start = (max_len_center - max_len) // 2
        end = start + max_len
        res = s[start:end]
        return res

if __name__=="__main__":
    str = input()
    s = Solution()
    print(s.manacher(str),end=" ") 