const maxSubArray = function(nums) {
  let [s, m] = [0, -10001]
  for (let n of nums) {
    s = Math.max(n, n+s)
    m = Math.max(m, s)
  }
  return m;
}

