class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n <= 2) {
      return n;
    }
    int i = 2;
    while (i < n) {
      if(nums[i-2] == nums[i-1] && nums[i-1] == nums[i]) {
        nums.erase(nums.begin() + i);
        n--;
        continue;
      }
      i++;
    }
    return n;
  }
};

