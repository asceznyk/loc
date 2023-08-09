from sys import stdin, stdout


def stdin_line(): return stdin.readline().lstrip().rstrip()


def solve(w:int):
    if w == 2: print("NO"); return
    print(f"{'YES' if not ((w-2)%2) else 'NO'} \n")


def main():
    w = int(stdin_line())
    solve(w)
    return 0


if __name__ == '__main__':
    main()


