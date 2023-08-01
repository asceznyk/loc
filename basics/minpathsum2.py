from typing import List


inf = int(1e+9)


def solve(grid: List[List[int]], i:int=0, j:int=0, down:int=0):
    n, m = len(grid), len(grid[i])
    if i == n-1 and j == m-1: return grid[i][j]
    return grid[i][j] + min(
        inf if i+1 > n-1 or down else solve(grid, i+1, j, 1),
        inf if j+1 > m-1 else solve(grid, i, j+1, 0)
    )


def main():
    ans1 = solve([
        [3,2,1,3],
        [1,9,2,3],
        [9,1,5,4]
    ])

    ans2 = solve([
        [4,6,1,6],
        [7,2,5,3],
        [8,9,2,1],
        [5,6,2,7],
    ])

    ans3 = solve([
        [1,2,3,4],
        [3,8,6,1],
        [2,3,6,6],
        [7,8,9,1]
    ])

    print(ans1, ans2, ans3)


if __name__ == '__main__':
    main()

