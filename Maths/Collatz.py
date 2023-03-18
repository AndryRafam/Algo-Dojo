def collatz(n:int):
    while(n!=1):
        print(n, "->", end=" ")
        if n%2!=0:
            n = 3*n+1
        else:
            n = n//2
    print(n)

if __name__ =="__main__":
    n = int(input())
    collatz(n)