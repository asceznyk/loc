if __name__ == "__main__":
  n = int(input())
  nums = [int(i) for i in str(input()).split(" ")]
  k, p = 0, 0
  for i in sorted(nums):
    if i != p: k += 1
    p = i
  print(k)



