func binarySearch(
  target int, mountainArr *MountainArray,
  l int, r int, reverse bool,
) int {
  for l <= r {
    m := int((l+r)/2)
    x := mountainArr.get(m)
    if (!reverse && x < target) || (reverse && x > target) {
      l = m+1
    } else if (!reverse && x > target) || (reverse && x < target) {
      r = m-1
    } else {
      return m
    }
  }
  return -1
}

func findInMountainArray(target int, mountainArr *MountainArray) int {
  n := mountainArr.length()
  l, r, s := 0, n-1, -1
  for l <= r {
    m := int((l+r)/2)
    x, p, q := mountainArr.get(m), -1, -1
    if m > 0 { p = mountainArr.get(m-1) }
    if m < n-1 { q = mountainArr.get(m+1) }
    if x > p && x > q {
      s = m
      break
    }
    if p > x && x > q { r = m-1 } 
    if q > x && x > p { l = m+1 }
  }
  ans := binarySearch(target, mountainArr, 0, s, false)
  if (ans != -1) {
    return ans
  }
  return binarySearch(target, mountainArr, s, n-1, true) 
}


