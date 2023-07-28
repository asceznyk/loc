def count_ways_k(n:int, k:int):
    dp = [[0]*(k+1) for _ in range(n+1)]
    dp[0][0] = 1
    dp[1][1] = 1

    for i in range(1, n+1):
        for j in range(1, k+1):
            dp[i][j] = dp[i-1][j-1] + dp[i-2][j-1]

    print(dp)
    return sum(dp[n])

print(count_ways_k(5, 3))

