# CodeForce Problem 158A

n = int()
k = int()
p = int()
count = 0
n = int(input())
k = int(input())

arr = list()
arr = []
for i in range(n):
    p = int(input())
    arr.append(p)

j = 0
while(arr[j]>=arr[k] and arr[j]>0):
    count+=1
    j+=1

print(count)
