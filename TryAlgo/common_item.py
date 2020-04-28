# Common item

class Solution(object):
    def common(self,arr1:list,arr2:list)->list:
        return list(set(arr1) & set(arr2))



if __name__=='__main__':
    arr1 = [3,6,5,3,9,2]
    arr2 = [3,5,3,2,4]
    s = Solution()
    print(s.common(arr1,arr2))
