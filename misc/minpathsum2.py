from typing import List


inf = int(1e+9)


def solve_dfs(grid: List[List[int]], i:int=0, j:int=0, down:int=0):
    n, m = len(grid), len(grid[i])
    if i == n-1 and j == m-1: return grid[i][j]
    return grid[i][j] + min(
        inf if i+1 > n-1 or down else solve_dfs(grid, i+1, j, 1),
        inf if j+1 > m-1 else solve_dfs(grid, i, j+1, 0)
    )


def solve_dp(grid: List[List[int]]):
    n, m = len(grid), len(grid[0])
    dp = [[0 for _ in l] for l in grid]

    dp[0][0] = grid[0][0]
    for i in range(n):
        for j in range(m):
            if i == 0 and j == 0: continue
            dp[i][j] = grid[i][j] + min(
                inf if i-1 < 0 or else dp[i-1][j],
                inf if j-1 < 0 else dp[i][j-1]
            )

    print(dp[i][j])


def main():
    arr1 = [
        [3,2,1,3],
        [1,9,2,3],
        [9,1,5,4]
    ]

    arr2 = [
        [4,6,1,6],
        [7,2,5,3],
        [8,9,2,1],
        [5,6,2,7],
    ]

    arr3 = [
        [1,2,3,4],
        [3,8,6,1],
        [2,3,6,6],
        [7,8,9,1]
    ]

    ans1 = solve_dfs(arr1)
    ans2 = solve_dfs(arr2)
    ans3 = solve_dfs(arr3)

    print(ans1, ans2, ans3)

    solve_dp(arr1)
    solve_dp(arr2)
    solve_dp(arr3)


if __name__ == '__main__':
    main()

