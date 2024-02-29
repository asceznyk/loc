class Solution {
private:
  int binary_search(vector<int>& nums, int& target, int start, int end) {
    if(nums[start] > target) return -1;
    int a = start, b = end;
    while (a <= b) {
      int k = (a+b)/2;
      if (nums[k] == target) return k;
      if (nums[k] < target) a = k+1;
      else b = k-1;
    }
    return -1;
  }
public:
  int search(vector<int>& nums, int target) {
    int n = nums.size();
    int p = 0, q = n-1;
    if(n > 1 && nums.front() > nums.back()) {
      while (p <= q) {
        int k = (p+q)/2;
        if (nums[k] >= nums[0]) p = k+1;
        else q = k-1;
      }
    }
    return max(binary_search(nums, target, 0, p), binary_search(nums, target, p, n-1));
  }
};
