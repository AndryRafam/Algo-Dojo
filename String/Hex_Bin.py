# Hex to Binary
# https://edabit.com/challenge/NX5uRSLwuXwsqKfiR

# Author: Andry Rafam

def hex_bin(s:str)->str:
	res = ""
	dico = {'A':"1010",'B':"1011",'C':"1100",'D':"1101",'E':"1110",'F':"1111"}
	for x in s:
		for (key,val) in dico.items():
			if(x==key):
				res+=val
	return res

if __name__=='__main__':
	test = "0xFF"
	print(hex_bin(test),end="\n") # 11111111
