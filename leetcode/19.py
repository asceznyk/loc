class Solution:
  def removeNthFromEnd(self, head:Optional[ListNode], n:int) -> Optional[ListNode]:
    l, i = 0, 0
    ptr1 = head
    while head:
      l += 1
      head = head.next
    if n == l:
      return ptr1.next
    ptr2 = ptr1
    while ptr1:
      if l-i == n+1:
        ptr1.next = ptr1.next.next
        break
      i += 1
      ptr1 = ptr1.next
    return ptr2

