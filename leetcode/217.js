const containsDuplicate = function(nums) {
  let record = {};
  for(let i=0; i < nums.length; i++) {
    if(nums[i] in record) return true;
    record[nums[i]] = 1;
  }
  return false;
}

