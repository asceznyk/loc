from typing import List
from sys import stdin, stdout


def stdin_line(): return stdin.readline().lstrip().rstrip()


def solve(m:List):
    m = sorted(m)
    stdout.write(f"{max(m[0]*m[1], m[-2]*m[-1])} \n")


def test():
    from random import randint
    rmax = 10**9
    m = [randint(-rmax, rmax) for _ in range(10**5)]
    solve(m)


def main():
    t = int(stdin_line())
    stdout.write("\n")
    for _ in range(t):
        _ = int(stdin_line())
        m = [int(k) for k in stdin_line().split(' ')]
        solve(m)

    return 0


if __name__ == '__main__':
    test()
    main()

