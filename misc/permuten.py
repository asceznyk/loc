from __future__ import annotations
from typing import List, Union


class Node:
    def __init__(self, value:int, parent:Node=None):
        self.value = value
        self.parent = parent


def solve(n:int, p:Union[Node,None], a:List[Node]):
    if n <= 0: return [Node(n, p)] if n == 0 else [None]
    m =[]
    for x in [Node(n.value) for n in a]:
        x.parent = p
        m.extend(solve(n-x.value, x, a))
    return m


def print_set(m:List[Node]):
    for node in m:
        if node is None: continue
        a = []
        while node.parent is not None:
            a.append(node.parent.value)
            node = node.parent
        print(a)


def main():
    m = solve(5, None, [Node(1), Node(2), Node(5)])
    print_set(m)
    m = solve(6, None, [Node(1), Node(3), Node(4)])
    print_set(m)


if __name__ == '__main__':
    main()

