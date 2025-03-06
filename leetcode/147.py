class Solution:
  def insertionSortList(self, head:Optional[ListNode]) -> Optional[ListNode]:
    arr = []
    curr = head
    while curr:
      arr.append(curr.val)
      curr = curr.next
    arr.sort()
    node = ListNode(arr[0])
    res = node
    for i in range(1, len(arr)):
      node.next = ListNode(arr[i])
      node = node.next
    return res


