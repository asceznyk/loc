from typing import List


def solve_dp(n:int, a:List[int]):
    dp = [0]*(n+1)

    dp[0] = 1
    for i in range(1, n+1):
        s = f""
        for x in a:
            s += f"{i}-{x}, " if i-x >= 0 else ""
            dp[i] += dp[i-x] if i-x >= 0 else 0
        print(s, i)

    print(f"ways: {dp[n]}")


def solve_dfs(n:int, a:List[int]):
    if n <= 0: return 1 if n == 0 else 0

    s = 0
    p = f""
    for x in a:
        p += f"{n}-{x}, " if n-x >= 0 else ""
        s += solve_dfs(n-x, a) if x > 0 and x <= n else 0
    print(p, n)
    return s


def main():
    solve_dp(3, [0,1,3])
    solve_dp(4, [1,2,3])
    solve_dp(5, [1,2,5])
    solve_dp(7, [1,2,3,4,5,6])

    print(solve_dfs(3, [0,1,3]))
    print(solve_dfs(4, [1,2,3]))
    print(solve_dfs(5, [1,2,5]))
    print(solve_dfs(7, [1,2,3,4,5,6]))


if __name__ == '__main__':
    main()

