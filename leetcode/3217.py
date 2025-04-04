class Solution:
  def modifiedList(self, nums:List[int], head:Optional[ListNode]) -> Optional[ListNode]:
    uniq = set(nums)
    arr, res = [], []
    curr = head
    while curr:
      arr.append(curr.val)
      curr = curr.next
    if not arr: return None
    for x in arr:
      if x in uniq: continue
      res.append(x)
    node = ListNode(res[0])
    ans = node
    for x in res[1:]:
      node.next = ListNode(x)
      node = ans.next
    return ans


