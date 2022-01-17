def miniMaxSum(arr):
    maxs = sum(arr) - min(arr)
    mins = sum(arr) - max(arr)

    print(mins, maxs)

miniMaxSum([5,5,5,5,5])
miniMaxSum([1,2,3,4,5])
miniMaxSum([1,3,5,7,9])
