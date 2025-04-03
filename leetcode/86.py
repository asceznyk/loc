class Solution:
  def partition(self, head:Optional[ListNode], x:int) -> Optional[ListNode]:
    arr = []
    curr = head
    while curr:
      arr.append(curr.val)
      curr = curr.next
    if not arr: return None
    less, geql = [], []
    for k in arr:
      if k < x: less.append(k)
      else: geql.append(k)
    less.extend(geql)
    node = ListNode(less[0])
    res = node
    for i in range(1, len(less)):
      node.next = ListNode(less[i])
      node = node.next
    return res

