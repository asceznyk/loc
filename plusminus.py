import math

def plusMinus(arr):
    rp = len(list(filter(lambda x: x > 0, arr))) / len(arr)
    rn = len(list(filter(lambda x: x < 0, arr))) / len(arr)
    rz = len(list(filter(lambda x: x == 0, arr))) / len(arr)

    print(f"{rp:.6f}")
    print(f"{rn:.6f}")
    print(f"{rz:.6f}")

plusMinus([-1,-0,1,2,3,-6,-7,-8,0])
