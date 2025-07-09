class Solution:
  def survivedRobotsHealths(
    self,
    positions:List[int],
    healths:List[int],
    directions:str
  ) -> List[int]:
    robots = [[p,h,d,i] for i, (p,h,d) in enumerate(zip(positions, healths, directions))]
    robots = sorted(robots, key = lambda x:x[0])
    stack = []
    for robot in robots:
      [rp,rh,rd,ri] = robot
      add = True
      while len(stack) > 0 and stack[-1][2] == 'R' and rd == 'L':
        [sp,sh,sd,si] = stack[-1]
        if sh < rh:
          stack.pop()
          rh -= 1
          robot[1] = rh
        elif sh == rh:
          stack.pop()
          add = False
          break
        else:
          add = False
          sh -= 1
          stack[-1][1] = sh
          break
      if add: stack.append(robot)
    if not len(stack): return []
    stack = sorted(stack, key=lambda x: x[3])
    return [h for (p,h,d,i) in stack]


