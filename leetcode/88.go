func reassign(arr1 []int, arr2 []int) []int {
  for i := 0; i < len(arr2); i++ {
    arr1[i] = arr2[i]
  }
  return arr1
}

func merge(nums1 []int, m int, nums2 []int, n int)  {
  var res []int
  i, j := 0, 0
  if n == 0 {
    for i < m {
      res = append(res, nums1[i])
      i++
    }
    nums1 = reassign(nums1, res)
    return
  }
  for i < m && j < n {
    c1 := nums1[i]
    c2 := nums2[j]
    if c1 <= c2 {
      res = append(res, c1)
      i++
    } else {
      res = append(res, c2)
      j++
    }
  }
  for i < m {
    res = append(res, nums1[i])
    i++
  }
  for j < n {
    res = append(res, nums2[j])
    j++
  }
  nums1 = reassign(nums1, res)
}

