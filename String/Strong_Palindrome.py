# AtCoder beginner contest 159: Problem B

def isPalindrome(s:str)->bool:
	left = 0
	right = len(s)-1
	while(left < right):
		if s[left]!=s[right]:
			return False
		
		left+=1
		right-=1
	
	return True
	
def strongPalindrome(s:str)->bool:
	n = len(s)
	l = (n-1)//2
	r = ((n-1)+3)//2
	
	a = s[0:l]
	b = s[r:r+n]
	
	if isPalindrome(s) and isPalindrome(a) and isPalindrome(b):
		return True
	return False
	
if __name__=="__main__":
	s = "akasaka"
	print(strongPalindrome(s), end=" ")
