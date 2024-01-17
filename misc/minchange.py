import time

from typing import List


inf = int(1e+9)


def solve_dfs(n:int, a:List[int]):
    def dfs(n:int, a:List[int]) -> int:
        if n == 0: return 0
        if memo[n] < n+1: return memo[n]
        for x in a:
            if n-x < 0: continue
            memo[n] = min(dfs(n-x,a)+1, memo[n])
        return memo[n]
    memo = [n+1 for _ in range(n+1)]
    print(dfs(n, a))


def solve_dp(n:int, a:List[int]):
    dp = [inf]*(n+1)
    dp[0] = 0
    for i in range(1, n+1):
        for x in a:
            if i-x < 0: continue
            dp[i] = min(dp[i], dp[i-x]+1)
    print(dp[n])


