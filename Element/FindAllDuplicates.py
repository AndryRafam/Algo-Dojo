# Find all duplicates in an array

from collections import Counter

def findDupl1(nums:list)->list:
    h = Counter(nums)
    res = []
    for(key,val) in h.items():
        if(val==2):
            res.append(key)
    return res


if __name__=='__main__':
    nums = [4,3,2,7,8,2,3,1]
    for x in findDupl1(nums):
        print(x,end=" ")
    print("\n")