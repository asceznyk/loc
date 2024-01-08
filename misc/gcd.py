def gcd(a, b):
    while b: a, b = b, a % b
    return a


def gcd_arr(arr):
    res = arr[0]
    for i in range(1, len(arr)):
        res = gcd(res, arr[i])
    return res


a,b = 30,60
print(f"gcd {gcd(a,b)}")

