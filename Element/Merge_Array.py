# Merge two (not necessarily sorted) arrays
# O(nlogn + mlogm)+(n+m)) time complexity

def merge(a,b,res,n,m):
	a.sort()
	b.sort()

	i,j,k = 0,0,0
	while(i < n and j < m):
		if(a[i] <= b[j]):
			res[k]=a[i]
			i+=1
			k+=1
		else:
			res[k]=b[j]
			j+=1
			k+=1

	while(i < n):
		res[k]=a[i]
		i+=1
		k+=1

	while(j < m):
		res[k]=b[j]
		j+=1
		k+=1

a=[10,5,15]
b=[20,3,2,12]
n = len(a)
m = len(b)
res=[0 for i in range(n+m)]
merge(a,b,res,n,m)

for i in range(n+m):
	print (res[i],end=" ")
