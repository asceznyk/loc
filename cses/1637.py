if __name__ == "__main__":
  n = int(input())
  if len(str(n)) == 1: print(1)
  s = 0
  while n:
    n -= max([int(d) for d in str(n)])
    s += 1
  print(s)


