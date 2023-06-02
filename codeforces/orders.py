from typing import List
from sys import stdin, stdout

import random


def stdin_line(): return stdin.readline().lstrip().rstrip()


def solve(a:List[int], b:List[int]):
    a, b = sorted(a), sorted(b)

    n = len(a)
    p = 1
    r, k = n-1, 0

    if max(a) <= max(b): print(0); return

    for i in range(n, 0, -1):
        while(r >= 0 and a[r] > b[i-1]):
            r = r-1
            k = k+1
        p = p * max(0, (k - (n-i))) % (1e9+7)

    print(int(p))


def main():
    t = int(stdin_line())
    for _ in range(t):
        n = int(stdin_line())
        a = [int(i) for i in stdin_line().split()]
        b = [int(i) for i in stdin_line().split()]
        solve(a, b)

    return 0


if __name__ == '__main__':
    main()

