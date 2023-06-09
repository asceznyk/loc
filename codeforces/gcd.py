def gcd(a, b):
    while b:
        a, b = b, a % b
        print(a,b)
    return a

def gcd_arr(arr):
    res = arr[0]
    for i in range(1, len(arr)):
        res = gcd(res, arr[i])
    return res

#arr = [30, 60, 90, 120, 125, 125]
#print("GCD of the array is :", gcd_arr(arr))

a,b = 14,7
print(f"gcd {gcd(a,b)}")

