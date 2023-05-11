"""
Longest palindromic substring

Solution1: Naive approach, O(N³) time complexity
Solution2-3: Expand around the center, O(N²) time complexity
"""

# Naive approach
def longestPalindrome_1(s:str)->str:
    maxi = 0
    longest_pal = ""

    def isPalindrome(s:str)->bool:
        l = 0
        r = len(s)-1
        while l < r:
            if s[l]!=s[r]:
                return False
            l+=1
            r-=1
        return True

    for i in range(len(s)):
        for j in range(i+1,len(s)+1):
            temp = s[i:j]
            if isPalindrome(temp) and maxi < len(temp):
                maxi = len(temp) 
                longest_pal = temp 
        
    return longest_pal

#-------------------------------------------------

# Expand around the center, 1st version: deal with odd len and even len separately
def longestPalindrome_2(s:str)->str:
    if(len(s) < 2):
        return s

    def expandCenter(s:str, l:int, r:int)->int:
        while(l >= 0 and r < len(s) and s[l]==s[r]):
            l-=1
            r+=1
        return r-l-1
    
    start = 0
    end = 0
    for i in range(len(s)):
        odd_len = expandCenter(s,i,i)
        even_len = expandCenter(s,i,i+1)
        length = max(odd_len,even_len)
        if(length > end-start):
            start = i-((length-1)//2)
            end = i+(length//2)
    
    return s[start:end+1]

#-------------------------------------------------

# Expand around the center, 2nd version: deal with odd len and even len at the same time
def longestPalindrome_3(s:str)->str:
    s_prime = '#'+'#'.join(s)+'#'
    #pal_radius = [0 for i in range(len(s_prime))]
    start = 0
    end = 0
    center = 0
    while(center < len(s_prime)):
        radius = 0
        l = center-(radius+1)
        r = center+(radius+1)
        while(l >=0 and r < len(s_prime) and s_prime[l] == s_prime[r]):
            l-=1
            r+=1
            radius+=1
            #pal_radius[center] = radius
            if(radius > end-start):
                start = (center-radius)//2
                end = (center+radius)//2
        
        center+=1
            
    return s[start:end]

if __name__=="__main__":
    test = "xoxoxbaobab"
    print(longestPalindrome_3(test),end=" ")