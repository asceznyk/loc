from typing import List


def solve(n:int, a:List[int]):
    k = len(a)
    dp = [[0]*(n+1) for _ in range(k+1)]

    for j in range(n+1): dp[0][j] = 0
    for i in range(k+1): dp[i][0] = 1
    for i in range(1, k+1):
        for j in range(1, n+1):
            p = j-a[i-1]
            dp[i][j] = dp[i-1][j] + (0 if p < 0 else dp[i][p])

    print(dp[k][n])


def main():
    solve(5, [1,2,5])
    solve(6, [1,3,5])


if __name__ == '__main__':
    main()

