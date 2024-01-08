from typing import List


def solve_dfs(n:int, a:List[int]):
    if n <= 0: return 1 if n == 0 else 0
    s = 0
    for x in a: s += solve_dfs(n-x, a) if x > 0 and n-x >= 0 else 0
    return s


def solve_dp(n:int, a:List[int]):
    dp = [0]*(n+1)
    dp[0] = 1
    for i in range(1, n+1):
        for x in a: dp[i] += dp[i-x] if i-x >= 0 else 0
    print(dp[n])


def main():
    print(solve_dfs(3, [0,1,3]))
    print(solve_dfs(4, [1,2,3]))
    print(solve_dfs(5, [1,2,5]))
    print(solve_dfs(7, [1,2,3,4,5,6]))

    solve_dp(3, [0,1,3])
    solve_dp(4, [1,2,3])
    solve_dp(5, [1,2,5])
    solve_dp(7, [1,2,3,4,5,6])


if __name__ == '__main__':
    main()

