from sys import stdin, stdout


def stdin_line(): return stdin.readline().lstrip().rstrip()


def solve(n:int):
  if n <= 1:
    print("1")
    return
  elif n % 2:
    print("-1")
    return

  s = ""
  p = [i+1 for i in range(n)]
  for even, odd in zip(p[1::2], p[::2]):
    s += f"{even} {odd} "
    print(s)


def test():
  import random
  from random import randint

  ## edge tests
  for n in range(1, 101):
    solve(n)


def main():
  t = int(stdin_line())
  print("")
  for _ in range(t):
    n = int(stdin_line())
    solve(n)

    return 0


if __name__ == '__main__':
  test()
  main()

