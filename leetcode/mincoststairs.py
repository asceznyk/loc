def min_cost_stairs(cost):
    n = len(cost)
    dp = [0 for i in range(n+1)]
    dp2 = [0 for i in range(n+1)]
    dp[0], dp[1] = cost[0], cost[1]
    dp2[0], dp2[1] = int(1e+9), cost[1]
    for i in range(2, n+1):
        c = 0 if i == n else cost[i]
        dp[i] = c + min(dp[i-1], dp[i-2])
        dp2[i] = c + min(dp2[i-1], dp2[i-2])
    return min(dp[n], dp2[n])

