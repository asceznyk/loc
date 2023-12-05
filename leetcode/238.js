const productExceptSelf = function(nums) {
  let products = [];
  let yzp = 1;
  let nzp = 1;
  let c = 0;
  for(let k = 0; k < nums.length; k++) {
    let n = nums[k];
    yzp *= n; 
    if (n == 0) {
      c++;
      continue;
    }
    nzp *= n;
  };
  nzp = c >= 2 ? 0 : nzp;
  for (let i = 0; i < nums.length; i++) {
    let p = 1;
    let n = nums[i];
    if (n == 0) p *= nzp;
    else p *= yzp/n;
    products.push(p);
  };
  return products;
}

