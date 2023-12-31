from typing import Optional, List

class Solution:
    def mergeTwoLists(self, list1:Optional[ListNode], list2:Optional[ListNode]) -> Optional[ListNode]:
      head = ListNode()
      ans = head
      while list1 and list2:
        p1, p2 = list1.val, list2.val
        if p1 < p2:
          list1 = list1.next
          head.next = ListNode(p1)
        else:
          list2 = list2.next
          head.next = ListNode(p2)
        head = head.next
      head.next = list1 or list2
      return ans.next

