# AtCodre beginner contest 159: Strong palindrome

def is_palindrome(s:str)->bool:
    rev = reversed(s)
    return list(rev)==list(s)

def strong_palindrome(s:str)->bool:
    n = len(s)
    s1 = ""
    s2 = ""
    for i in range((n-1)//2):
        s1 += s[i]
    for j in range((n+2)//2,n):
        s2 += s[j]
    if(is_palindrome(s) and is_palindrome(s1) and is_palindrome(s2)):
        return True
    return False


if __name__=='__main__':
    test = "akasaka" #strong palindrome
    print(strong_palindrome(test))
