class Solution(object):
	def __init__(self,nums,k:int):
		self.nums = nums
		self.k = k
	def answer(self,nums,k:int)->int:
		self.count = 0
		self.n = len(self.nums)
		for i in range(self.n):
			if(self.nums[i] < self.k):
				self.count+=1
			self.prod = self.nums[i]
			for j in range(i+1,self.n):
				self.prod = self.prod*self.nums[j]
				if(self.prod < self.k):
					self.count+=1
		return self.count
		
if __name__=='__main__':
	arr = [10, 5, 2, 6]
	k = 100
	s = Solution(arr,k)
	print(s.answer(arr,k)) #8
	
