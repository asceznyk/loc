class Solution:
  def swapNodes(self, head:Optional[ListNode], k:int) -> Optional[ListNode]:
    n = 0
    curr = head
    while curr:
      n += 1
      curr = curr.next
    if n%2 == 1 and k == (n//2)+1:
      return head
    ptr, ptr1, ptr2, i = head, None, None, 1
    res = ptr
    while ptr:
      if i == k: ptr1 = ptr
      if i == (n-k+1): ptr2 = ptr
      if ptr1 and ptr2:
        ptr1.val, ptr2.val = ptr2.val, ptr1.val
        break
      i += 1 
      ptr = ptr.next
    return res

