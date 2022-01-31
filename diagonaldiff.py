def diagonalDiff(arr):
    ltrd, rtld = 0, 0 
    for y in range(len(arr)):
        ltrd += arr[y][y]
        rtld += arr[y][(len(arr)-1) - y]

    return abs(ltrd  - rtld)

arr = [
    [11, 2, 4],
    [4, 5, 6],
    [10, 8, -12]
]

diff = diagonalDiff(arr)
print(diff)


