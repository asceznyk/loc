class Solution:
  def racecar(self, target:int) -> int:
    queue = deque([(0,0,1)])
    mem = {}
    ans = 0
    while len(queue):
      steps, pos, speed = queue.popleft()
      if pos < 0 or pos > 2*target or mem.get((pos,speed), 0):
        continue 
      if pos == target:
        ans = steps
        break
      mem[(pos,speed)] = steps
      queue.append((steps+1, pos+speed, 2*speed))
      queue.append((steps+1, pos, (-1 if speed > 0 else 1)))
    return ans


