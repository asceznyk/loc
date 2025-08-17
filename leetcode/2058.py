class Solution:
  def nodesBetweenCriticalPoints(self, head:Optional[ListNode]) -> List[int]:
    curr = head
    prev = None
    store = [0,0]
    idx = 0
    minDist = 100000+7
    while curr:
      idx += 1
      if prev is None or curr.next is None:
        prev = curr
        curr = curr.next
        continue
      if (prev.val > curr.val and curr.val < curr.next.val) or \
          (prev.val < curr.val and curr.val > curr.next.val):
        if store[0] == 0: store[0] = store[1] = idx
        else:
          minDist = min(idx-store[1], minDist)
          store[1] = idx
      prev = curr
      curr = curr.next
    if store[1] == 0 or store[0] == store[1]: return [-1,-1]
    return [minDist, store[1]-store[0]]

