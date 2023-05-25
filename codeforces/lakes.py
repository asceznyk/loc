from typing import List, Tuple
from random import randint
from sys import stdin, stdout


def stdin_line(): return stdin.readline().lstrip().rstrip()


def solve(a:List):
    visited = [[0 for _ in range(len(a[0]))] for _ in range(len(a))]
    dirs = [(0,1), (0,-1), (1,0), (-1,0)]
    def dfs(visited:List[List[int]], i:int, j:int) -> int:
        total = a[i][j]
        visited[i][j] = 1
        for y,x in dirs:
            r, c = i+y, j+x
            if (
                r < 0 or r > len(a)-1 or c < 0 or c > len(a[i])-1 or
                visited[r][c] or
                a[r][c] == 0
            ): continue
            total += dfs(visited,r,c)

        return total

    s = 0
    for i in range(len(a)):
        for j in range(len(a[i])):
            if a[i][j] and (not visited[i][j]):
                s = max(s, dfs(visited,i,j))

    print(s)


def test():
    ## manual tests

    solve([
        [1,2,0],
        [3,4,0],
        [0,0,5]
    ])

    solve([[0]])

    solve([
        [0,1,1],
        [1,0,1],
        [1,1,1]
    ])

    solve([
        [1,1,1,1,1],
        [1,0,0,0,1],
        [1,0,5,0,1],
        [1,0,0,0,1],
        [1,1,1,1,1]
    ])

    solve([
        [1,1,1,1,1],
        [1,0,0,0,1],
        [1,1,4,0,1],
        [1,0,0,0,1],
        [1,1,1,1,1]
    ])

    solve([
        [0,0,2,2,2,2,0,2,0],
        [0,2,1,2,0,0,1,2,0],
        [1,0,2,0,0,0,1,2,0]
    ])

    solve([
        [2],
        [0],
        [0],
        [1],
        [1]
    ])

    solve([
        [1],
        [2],
        [1],
        [2],
        [0],
        [0],
        [1],
        [1]
    ])

    for i in range(10**4):
       a = []
       n = 10 #randint(1, 10)
       m = 10 #randint(1, 10)
       for r in range(n):
           a.append([randint(0, 1000) for _ in range(m)])
       print(n,m)
       solve(a)


def main():
    t = int(stdin_line())
    stdout.write("\n")
    for _ in range(t):
        a = []
        n, m = tuple([int(k) for k in stdin_line().split()])
        for i in range(n):
            a.append([int(j) for j in stdin_line().split()])
        solve(a)

    return 0


if __name__ == '__main__':
    test()
    #main()

