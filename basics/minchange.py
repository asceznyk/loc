from typing import List


inf = int(1e+9)


def solve_dfs(n:int, a:List[int]) -> int:
    if n == 0: return 0
    m = inf
    for x in a:
        m = min(solve_dfs(n-x,a)+1 if n-x >= 0 else inf, m)
    return m


def solve_dp(n:int, a:List[int]):
    dp = [inf]*(n+1)
    dp[0] = 0
    for i in range(1, n+1):
        for x in a:
            dp[i] = min(dp[i], dp[i-x]+1 if i-x >= 0 else inf)
    print(dp[n])


def main():
    solve_dp(11, [5,5,1])
    solve_dp(6, [1,3,4])


if __name__ == '__main__':
    main()

