class Solution {
public:
  int numSubarraysWithSum(vector<int>& nums, int goal) {
    int n = nums.size();
    int ans = 0;
    if (goal == 0) {
      int k = 0;
      nums.push_back(1);
      for (int i = 0; i < n+1; i++) {
        int curr = nums[i];
        if (curr == 1) {
          ans += (k*(k+1)) / 2;
          k = 0;
        } else k++;
      }
    } else {
      vector<int> freq(2);
      int l = 0, r = 0, off = 0;
      while (true) {
        if (r < n) {
          int curr = nums[r];
          freq[curr]++;
          if (freq[1] <= goal) {
            r++;
            off += (freq[1] == goal) ? 1 : 0; 
            continue;
          }
          freq[curr]--;
        } else if (freq[1] < goal) break;
        while (l < r && freq[1] == goal) {
          freq[nums[l]]--;
          l++;
          ans += off;
        }
        off = 0; 
      }
    }
    return ans;
  }
};

