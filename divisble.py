(n, k) = map(int, input().split(' '))

ans = 0
for i in range(n):
    d = int(input())
    if d % k == 0:
        ans += 1

print(ans)


