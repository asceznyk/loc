def count_ways(n:int):
    dp = [0 for _ in range(n+1)]
    dp[0] = 1
    for i in range(1, n+1):
        dp[i] = dp[i-1] + dp[i-2]
    print(dp)
    return dp[n]


