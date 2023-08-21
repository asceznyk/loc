from sys import stdin, stdout

def stdin_line(): return stdin.readline().lstrip().rstrip()

def solve(n:int):
  l = [i+1 for i in range(n)]
  ans = 0
  for i in range(n):
    p = l[:i] + l[i:][::-1]
    e = [(i+1)*p[i] for i in range(n)]
    ans = max(ans, sum(e)-max(e))
  print(ans)

def main():
  t = int(stdin_line())
  for _ in range(t):
    n = int(stdin_line())
    solve(n)

if __name__ == "__main__":
  main()


