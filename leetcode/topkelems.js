/* O(n) - soln */

const topKFrequent = function (nums, k) {
  let topK = new Map();
  let ans = [];
  let arr = new Array(nums.length+1).fill(0);
  nums.forEach((e) => {
    let v = topK.get(e) || 0;
    topK.set(e, v+1);
  });
  for(let [key, val] of topK) {
    let prev = arr[val] || [];
    prev.push(parseInt(key));
    arr[val] = prev;
  }
  arr.reverse();
  for (let e of arr) {
    if(k <= 0) break;
    if(!e) continue;
    for (let i of e) {
      ans.push(i)
      k--;
    }
  }
  return ans;
}


/* O(n log n) - soln */

const topKFrequent = function (nums, k) {
  let topK = {};
  for (n in nums) {
    let x = nums[n];
    let v = topK[x] || 0;
    topK[x]  = v+1;
  }
  const entries = Object.entries(topK);
  entries.sort((a, b) => b[1] - a[1]);
  return entries.map(x => parseInt(x[0])).slice(0, k);
};


