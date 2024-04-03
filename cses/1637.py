if __name__ == "__main__":
  n = int(input())
  s = 0
  while n:
    n -= max([int(d) for d in str(n)])
    s += 1
  print(s)


