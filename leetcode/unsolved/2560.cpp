#include "../utils.h"
#include <climits>

class Solution {
public:
  int n = 0;
  int INF = 1e9+7;
  int dfs(
    int i, int b, int s, int k,
    vector<int>& nums, vector<vector<int>>& mem
  ) {
    if (i == n) return (s >= k ? 0 : INF);
    if (b) return mem[i][b] = dfs(i+1, b^1, s, k, nums, mem);
    else {
      return mem[i][b] = min(
        max(nums[i], dfs(i+1, b^1, s+1, k, nums, mem)),
        dfs(i+1, b, s, k, nums, mem)
      );
    }
  }
  int minCapability(vector<int>& nums, int k) {
    n = nums.size();
    vector<vector<int>> mem(n+1, vector<int>(2, INT_MAX));
    int ans = dfs(0, 0, 0, k, nums, mem);
    printf("ans = %d\n", ans);
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {2,3,5,9};
  sol.minCapability(nums, 2);
  nums = {2,7,9,3,1};
  sol.minCapability(nums, 2);
  return 0;
}
