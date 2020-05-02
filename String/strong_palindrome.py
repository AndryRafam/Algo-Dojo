# AtCoder beginner contest 159: Problem B

class Answer(object):
    def is_palindrome(self,s:str)->bool:
        self.rev = reversed(s)
        return list(self.rev)==list(s)

    def strong_pal(self,s:str)->bool:
        self.s1 = ""
        self.s2 = ""
        self.n = len(s)
        for i in range((self.n-1)//2):
            self.s1 += s[i]
        for j in range((self.n+2)//2,self.n):
            self.s2 += s[j]
        if(self.is_palindrome(s) and self.is_palindrome(self.s1) and self.is_palindrome(self.s2)):
            return True
        return False
    

if __name__=='__main__':
    test = "akasaka"
    s = Answer()
    print(s.strong_pal(test))
