from sys import stdin, stdout


def stdin_line(): return stdin.readline().lstrip().rstrip()


def solve():
    n = int(stdin_line())
    stdout.write(f"{(n+1)**2 + 1} \n")


def main():
    t = int(stdin_line())
    stdout.write("\n")
    for _ in range(t):
        solve()

    return 0


if __name__ == '__main__':
    main()


