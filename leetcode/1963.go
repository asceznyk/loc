func minSwaps(s string) int {
  var maxClose, currClose int = 0, 0
  for _, c := range s {
    if c == '[' { 
      currClose-- 
    } else { currClose++ }
    maxClose = max(currClose, maxClose)
  }
  return (maxClose+1)/2 
}

