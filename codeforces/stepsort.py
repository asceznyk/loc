from typing import List
from sys import stdin, stdout


def stdin_line(): return stdin.readline().lstrip().rstrip()


def solve(p:List, k:int):
    def k_check(arr:List) -> List:
        nopos = []
        for i in range(len(arr)):
            if (arr[i]-1) % k != i % k: nopos.append(i)
        return nopos

    n = len(p)
    psorted = sorted(p)
    x = k_check(p)

    if not len(x):
        stdout.write(f"{0}\n")
        return
    if len(x) == 2:
        stdout.write(f"{1}\n")
        return

    stdout.write(f"{-1}\n")


def test():
    import random
    from random import randint

    ## manual tests
    solve([3,1,2,4], 1)
    solve([3,4,1,2], 2)
    solve([3,1,4,2], 2)
    solve([3,2,4,1], 2)
    solve([4,5,9,1,8,6,10,2,3,7], 3)
    solve([4,6,9,1,8,5,10,2,3,7], 3)
    solve([4,6,9,1,8,5,10,3,2,7], 3)

    ## edge tests
    for i in range(5):
        n = randint(2, 2 * 10**5)
        k = randint(1, n-1)
        p = [i for i in range(n)]
        random.shuffle(p)
        solve(p, k)


def main():
    t = int(stdin_line())
    stdout.write("\n")
    for _ in range(t):
        n, k = tuple(int(i) for i in stdin_line().split(' '))
        p = [int(i) for i in stdin_line().split(' ')]
        solve(p, k)

    return 0


if __name__ == '__main__':
    test()
    main()

