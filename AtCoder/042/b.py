tab = list()
N = int(input())
L = int(input())
s = str()
res = str()

for i in range(N):
    s = str(input())
    tab.append(s)

tab.sort()

for x in tab:
    if(len(x)==L):
        res+=x

print(res)
