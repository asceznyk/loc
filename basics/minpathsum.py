from typing import List


def solve(grid: List[List[int]]):
    dp = [[0 for _ in l] for l in grid]

    dp[0][0] = grid[0][0]
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if i == 0 and j == 0: continue
            t = []
            if i > 0: t.append(dp[i-1][j])
            if j > 0: t.append(dp[i][j-1])
            dp[i][j] = grid[i][j] + (min(t) if len(t) else int(1e+9))

    print(dp[i][j])


def main():
    solve([
        [3,2,1,3],
        [1,9,2,3],
        [9,1,5,4]
    ])

    solve([
        [4,6,1,6],
        [7,2,5,3],
        [8,9,2,1],
        [5,6,2,7],
    ])


if __name__ == '__main__':
    main()

