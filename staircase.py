
def staircase(n):
    stairs = ''
    for i in range(1, n+1):
        stairs += (' ' * (n - i)) + ('#' * i) + ('\n' if i < n else '') 

    print(stairs)

staircase(11)
