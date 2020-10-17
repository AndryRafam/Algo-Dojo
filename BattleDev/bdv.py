def max_count(s:str):
	n = len(s)
	i = 0
	count = 0
	temp = []
	while(n//2+i < n):
		for j in range(i,n//2+i):
			if(s[j]=="x"):
				count+=1
				temp.append(count)
		i+=1
		count = 0
	temp.sort()
	return temp[len(temp)-1]

if __name__=='__main__':
	test = "xxooxxoxoooxxxoooxoxoxxooxxxoooxoxxxoxxxoxxooxxxxoxxxxoxoooooxoooooooxooxxxoxxoxxxoxooxxxoxoxxxoxxox"
	print(max_count(test),end="\n")
	
