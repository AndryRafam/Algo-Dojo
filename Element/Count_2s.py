"""Count 2s. Given an integer n, count the number of 2s that appear in all the number from 0 to n (inclusive)
From Gayle Laakmann Mcdowell - Cracking the coding interview, 6th edition.
Brute Force approach."""


def count_two(s:str)->int:
    count = 0
    for x in s:
        if ord(x)==50:
            count+=1
    return count

if __name__ == "__main__":
    n = int(input())
    s = ""
    for i in range(n+1):
        s = "".join([str(i),s])
    print(count_two(s))