//Complex solve
const maxProduct = function(nums) {
  let [maxP,q,c,f] = [Number.MIN_SAFE_INTEGER,1,0,1];
  for (let i = 0; i < nums.length; i++) {
    let a = nums[i];
    if(a == 0) {
      [q,c,f] = [1,0,1];
      maxP = Math.max(maxP, a);
      continue;
    }
    q *= a;
    if(a < 0) {
      c++;
      f = f == 1 ? q : f;
    }
    let p = (c%2 && q != a) ? Math.max(Math.floor(q/f), Math.floor(q/a)): q; 
    maxP = Math.max(maxP, p);
  }
  return maxP;
}

//Simpler solve
const maxProduct = function(nums) {
  let n = nums.length;
  let [maxP,prefix,suffix] = [Number.MIN_SAFE_INTEGER,1,1];
  for (let i = 0; i < n; i++) {
    if(prefix == 0) prefix = 1;
    if(suffix == 0) suffix = 1;
    prefix *= nums[i];
    suffix *= nums[n-i-1];
    maxP = Math.max(maxP, prefix, suffix);
  }
  return maxP;
}

