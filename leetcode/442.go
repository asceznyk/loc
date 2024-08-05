func findDuplicates(nums []int) []int {
  counts := make(map[int]int)
  for i := 0; i < len(nums); i++ { counts[nums[i]]++ }
  var ans = []int{}
  for k, v := range counts {
    if v == 1 { continue }
    ans = append(ans, k)
  } 
  fmt.Println(ans)
  return ans
}
