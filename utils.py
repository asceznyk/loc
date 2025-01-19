import heapq
from heapq import heappop, heappush

from collections import deque
from typing import List, Dict, Optional, Union, Tuple

class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right

class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = None

def buildSinglyLL(arr:List) -> ListNode:
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

def buildBinaryTree(nums:List[Union[int,None]]) -> Union[TreeNode,None]:
  n = len(nums)
  if n <= 0: return None
  i = 0
  root = TreeNode(nums[0])
  queue = deque([root])
  while queue:
    node = queue.popleft()
    if node is None: continue
    l, r = 2*i+1, 2*i+2
    if l <= n-1 and nums[l] is not None:
      node.left = TreeNode(nums[l])
      queue.append(node.left)
    if r <= n-1 and nums[r] is not None:
      node.right = TreeNode(nums[r])
      queue.append(node.right)
    i += 1
  return root

def traverseBinaryTree(root:TreeNode) -> List[int]:
  visited = []
  stack = [root]
  while stack:
    node = stack.pop()
    if not node: continue
    visited.append(node.val)
    stack.append(node.right)
    stack.append(node.left)
  return visited

def callObjMethods(obj:object, funcs:List[str], largs:List[List[Union[str,int]]]):
  ins = obj(*largs[0])
  callees = {methodName:getattr(ins, methodName) for methodName in set(funcs[1:])}
  for func, args in zip(funcs[1:], largs[1:]): print(func, args, callees[func](*args))

