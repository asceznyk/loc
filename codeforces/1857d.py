from typing import List
from sys import stdin, stdout

inf = int(1e+9)

def stdin_line(): return stdin.readline().lstrip().rstrip()

def solve(n:int, a:List[int], b:List[int]):
  verts = [0]
  c = [x-y for x,y in zip(a,b)]
  maxc = max(c)
  verts = [(i+1) for i in range(n) if maxc == c[i]]
  print(len(verts))
  print(' '.join(map(lambda x: str(x), verts)))

def main():
  t = int(stdin_line())
  for _ in range(t):
    n = int(stdin_line())
    a = [int(i) for i in stdin_line().split(' ')]
    b = [int(i) for i in stdin_line().split(' ')]
    solve(n, a, b)

if __name__ == "__main__":
  main()


