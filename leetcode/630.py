class Solution:
  def scheduleCourse(self, courses:List[List[int]]) -> int:
    courses = sorted(courses, key=lambda x:x[1])
    maxHeap, heapSum, ans = [], 0, 0
    for course in courses:
      d, l = course
      heappush(maxHeap, -d)
      heapSum += d
      while maxHeap and heapSum > l:
        heapSum += heappop(maxHeap)
      ans = max(ans, len(maxHeap))
    return ans

