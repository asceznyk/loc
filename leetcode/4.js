const findMedianSortedArrays = (nums1, nums2)  => {
  let nums = [nums1, nums2].flat().sort((a, b) => a-b);
  let median = 0;
  let total = nums.length;
  if(nums.length % 2) {
    median = nums[(total-1)/2];
  } else {
    median = (nums[Math.floor((total-1)/2)] + nums[Math.floor(total/2)]) / 2;
  }
  return median;
}

