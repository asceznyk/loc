import heapq

from typing import List, Dict, Optional, Union

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

def buildBinaryTree(nums:List[int]) -> Union[TreeNode,None]:
  n = len(nums)-1
  if n < 0: return None
  def getNode(i:int) -> Union[None,TreeNode]:
    if i > n: return
    x = nums[i]
    return None if x is None else TreeNode(x)
  def build(root:TreeNode, i:int):
    li, ri = (2*i)+1, (2*i)+2
    if not root: return
    root.left = getNode(li)
    root.right = getNode(ri)
    build(root.left, li)
    build(root.right, ri)
  root = TreeNode(nums[0])
  build(root, 0)
  return root

def traverseBinaryTreeDFS(root:TreeNode):
  stack = [root]
  visited = []
  while stack:
    node = stack.pop()
    if not node: continue
    visited.append(node.val)
    stack.append(node.right)
    stack.append(node.left)
  return visited

def callObjMethods(obj:object, funcs:List[str], largs:List[List[Union[str,int]]]):
  ins = obj(*largs[0])
  callees = {method_name:getattr(ins, method_name) for method_name in set(funcs[1:])}
  for func, args in zip(funcs[1:], largs[1:]):print(func, args, callees[func](*args))

