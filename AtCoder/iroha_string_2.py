# AtCoder Regular contest 058 (Problem F) O(N²) complexity

N = int(input())
L = int(input())
tab = []
res = []
for i in range(N):
    s = str(input())
    tab.append(s)
for i in range(len(tab)):
    for j in range(i+1,len(tab)):
        if(len(tab[i]+tab[j])==L):
            res.append(tab[i]+tab[j])

            
if __name__=='__main__':
    if(len(res)!=0):
        print(min(res))
    else:
        print("Empty")
