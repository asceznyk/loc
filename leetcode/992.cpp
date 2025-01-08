class Solution {
public:
  int subarraysAtMoskK(vector<int>& nums, int k) {
    int n = nums.size();
    map<int,int> freq;
    int i = 0, j = 0, res = 0;
    while (j < n) {
      int x = nums[j];
      freq[x]++;
      while ((int)freq.size() > k) {
        int p = nums[i];
        i++;
        freq[p]--;
        if (freq[p] == 0) freq.erase(p);
      }
      res += j-i+1;
      j++;
    }
    return res;
  }
  int subarraysWithKDistinct(vector<int>& nums, int k) {
    return subarraysAtMoskK(nums, k) - subarraysAtMoskK(nums, k-1);
  }
};

