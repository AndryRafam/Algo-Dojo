# Hidden Anagram
# https://edabit.com/challenge/vxWGJmtjpWtu36xfj

def lowerconcat(s:str)->str:
	t = ""
	for x in s:
		if((ord(x)>=65 and ord(x)<=90) or (ord(x)>=97 and ord(x)<=122)):
			t+=x.lower()
		else:
			t+=""
	return t

def is_anagram(a:str,b:str)->bool:
	d = 0
	for x in a:
		d+=ord(x)
	for y in b:
		d-=ord(y)
	return True if(d==0) else False

def hiddenAnagram(a:str,b:str)->str:
	temp = ""
	for i in range(len(a)):
		for j in range(1,len(a)+1-i):
			temp = a[i:j]
			if(is_anagram(temp,b)):
				return temp
	return "Not found"


if __name__=='__main__':
	a = "D  e b90it->?$ (c)a r...d,,#~"
	b = "bad credit"

	s = "Bright is the moon"
	t = "Bongo mirth"

	print(hiddenAnagram(lowerconcat(a),lowerconcat(b)),end="\n") # debitcard
	print(hiddenAnagram(lowerconcat(s),lowerconcat(t)),end="\n") # Not found
