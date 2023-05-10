fibbs = [0, 1]
def fibb_fast(n):
    if n < 2:
        return fibbs[n]
    else:
        fibbs.append(fibbs[n-1] + fibbs[n-2])
        return fibbs[-1]

for i in range(100):
    print(fibb_fast(i))
