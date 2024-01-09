from typing import List

class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right

class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = None

def linkedList(arr:List) -> ListNode:
  if not arr: return None
  node = ListNode(arr[0])
  head = node
  for i in range(1, len(arr)):
    node.next = ListNode(arr[i])
    node = node.next
  return head

def catLL(head:Optional[ListNode]):
  s = ""
  while head:
    s += f"{head.val} -> "
    head = head.next
  print(f"{s}None")

def binarySearch(self, nums:List[int], target:int) -> int:
  lp = 0
  rp = len(nums)-1
  while lp <= rp:
    mp = (rp+lp)//2
    n = nums[mp]
    if n == target: return True
    if n < target: lp = mp+1
    elif n > target: rp = mp-1
  return False

def buildBinaryTree(nums:List[int]) -> TreeNode:
  for n in nums
