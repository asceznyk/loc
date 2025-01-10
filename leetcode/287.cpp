class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int ans = 0;
    sort(nums.begin(), nums.end()); 
    for (int i = 1; i < (int)nums.size(); i++) {
      if (nums[i-1] != nums[i]) continue;
      ans = nums[i];
      break;
    }
    return ans; 
  }
};


