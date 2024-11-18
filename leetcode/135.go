func candy(ratings []int) int {
  n := len(ratings)
  candies := make([]int, n)
  for i := range candies {
    candies[i] = 1
  }
  for i := 1; i < n; i++ {
    if ratings[i] > ratings[i-1] && candies[i] <= candies[i-1] {
      candies[i] = 1 + candies[i-1] 
    }
  }
  for i := n-2; i > -1; i-- {
    if ratings[i] > ratings[i+1] && candies[i] <= candies[i+1] {
      candies[i] = 1 + candies[i+1]
    }
  }
  s := 0
  for _, v := range candies {
    s += v
  }
  return s
}


