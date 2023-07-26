from typing import List
from sys import stdin, stdout


def stdin_line(): return stdin.readline().lstrip().rstrip()


def solve(p:List, k:int):
    x = 0
    for i in range(len(p)):
        if (p[i]-1) % k != i % k: x += 1

    if not x:
        print(f"{0}")
        return
    elif x == 2:
        print(f"{1}")
        return
    print(f"{-1}")


def main():
    t = int(stdin_line())
    print("")
    for _ in range(t):
        n, k = tuple(int(i) for i in stdin_line().split(' '))
        p = [int(i) for i in stdin_line().split(' ')]
        solve(p, k)

    return 0


if __name__ == '__main__':
    main()

