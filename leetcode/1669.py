class Solution:
  def mergeInBetween(self, list1:ListNode, a:int, b:int, list2:ListNode) -> ListNode:
    lla, headb, i, j = list1, list1, 0, 0
    heada = lla
    while j < b+1:
      j += 1
      headb = headb.next
    while lla.next:
      if i == a-1:
        lla.next = list2
      i += 1
      lla = lla.next
    lla.next = headb
    return heada

