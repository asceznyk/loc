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
    print("")
    for _ in range(t):
        n, k = tuple(int(i) for i in stdin_line().split(' '))
        p = [int(i) for i in stdin_line().split(' ')]
        solve(p, k)

    return 0


if __name__ == '__main__':
    test()
    main()

