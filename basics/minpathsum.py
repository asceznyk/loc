from typing import List


inf = int(1e+9)


def solve_dp(grid: List[List[int]]):
    n, m = len(grid), len(grid[0])
    dp = [[0 for _ in l] for l in grid]

    dp[0][0] = grid[0][0]
    for i in range(n):
        for j in range(m):
            if i == 0 and j == 0: continue
            dp[i][j] = grid[i][j] + min(
                inf if i-1 < 0 or down else dp[i-1][j],
                inf if j-1 < 0 else dp[i][j-1]
            )

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

