# CodeForce Problem 981A

def is_palindrome(s:str)->bool:
    rev = str()
    rev = reversed(s)
    return list(rev)==list(s)

def longest_nonpal(s:str)->int:
    res = []
    for i in range(len(s)):
        for j in range(1,len(s)+1-i):
            if(not is_palindrome(s[i:j])):
                res.append(len(s[i:j]))

    if(len(res)==0):
        return 0
    return max(res)

                           

if __name__=='__main__':
    s = input()
    print(longest_nonpal(s))
