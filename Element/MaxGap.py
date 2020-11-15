# Given an unsorted array, find the maximum difference 
# between the successive elements in its sorted form.
# Return 0 if the array contains less than 2 elements.

# https://leetcode.com/problems/maximum-gap/

def maximumGap(nums)->int:
	n = len(nums)
	max = 0
	if((nums[0]-nums[n-1])>0):
		 max=abs(nums[0]-nums[n-1])
	for x in range(n-1):
		temp = nums[x+1]-nums[x]
		if(temp>0 and max<=temp):
			max=temp
	return (max if(n>=2) else 0)


if __name__=='__main__':
	vec1 = [3,6,9,1]
	vec2 = [0]
	print(maximumGap(vec1), end="\n") # 3
	print(maximumGap(vec2), end="\n") # 0
