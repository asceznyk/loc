class Solution:

  def maxHeapify(self, nums:List[int], i:int, n:int):
    largest = i;
    l = 2*i + 1;
    r = 2*i + 2;
    if l < n and nums[l] > nums[largest]: largest = l
    if r < n and nums[r] > nums[largest]: largest = r
    if largest != i:
      nums[largest], nums[i] = nums[i], nums[largest]
      self.maxHeapify(nums, largest, n)

  def sortArray(self, nums:List[int]):
    n = len(nums)
    for i in range(n//2, -1, -1): self.maxHeapify(nums, i, n)
    for i in range(n-1, 0, -1):
      nums[0], nums[i] = nums[i], nums[0]
      self.maxHeapify(nums, 0, i)
    return nums
