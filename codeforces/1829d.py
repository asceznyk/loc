from sys import stdin, stdout


def stdin_line(): return stdin.readline().lstrip().rstrip()


def solve(n:int, m:int, cache:dict) -> str:
  if m > n or (n % 3 and n != m): return "NO"
  elif m == n: return "YES"

  k = n//3
  for x in [k, 2*k]:
    if x in cache: r = cache[x]
    else:
      r = solve(x, m, cache)
      cache[x] = r
      if r == "YES": break
    return r


def test():
  import random
  from random import randint

  ## edge tests
  for i in range(1000):
    n = randint(1, 10**7)
    m = randint(1, 10**7)
    print(n, m)
    print(solve(n, m, {}))


def main():
  t = int(stdin_line())
  print("")
  for _ in range(t):
    n, m = stdin_line().split()
    r = solve(int(n), int(m), {})
    print(r)

    return 0


if __name__ == '__main__':
  test()
  main()




