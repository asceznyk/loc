from sys import stdin, stdout

import math

n, m, a = [int(x) for x in stdin.readline().rstrip().split()]

def least_flagstones(n, m, a): return math.ceil(n/a) * math.ceil(m/a) 

stdout.write(str(least_flagstones(n,m,a))+"\n")
