func max(a int, b int) int {
  if a > b { return a; } 
  return b;
}

func bagOfTokensScore(tokens []int, power int) int {
  sort.Ints(tokens);
  var l, r int = 0, len(tokens)-1
  var curr, score int = 0, 0
  for l <= r {
    x := tokens[l]
    if power >= x {
      power -= x
      curr++
      l++
    } else if curr >= 1 {
      power += tokens[r]
      curr--
      r--
    } else { break }
    score = max(score, curr)
  }
  return score;
}

