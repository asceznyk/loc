class Solution:
  def removeNodes(self, head:Optional[ListNode]) -> Optional[ListNode]:
    ptrH = head
    nums = []
    while ptrH:
      nums.append(ptrH.val)
      ptrH = ptrH.next
    cmax = 0
    maxs = []
    for i in range(len(nums)-1, -1, -1):
      curr = nums[i]
      if curr >= cmax:
        cmax = curr
        maxs.append(curr)
    ptrR = ListNode(maxs[-1])
    res = ptrR
    for i in range(len(maxs)-2, -1, -1):
      nxt = ListNode(maxs[i])
      ptrR.next = nxt
      ptrR = ptrR.next
    return res

