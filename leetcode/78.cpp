#include <iostream>
#include <bits/stdc++.h>

class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<int> ss{};
      vector<vector<int>> pos{};
      search(nums, ss, pos, 0);
      return pos;
    }
  private:
    void search(vector<int>& nums, vector<int>& ss, vector<vector<int>>& pos, int k) {
      if (k == nums.size()) {
        pos.push_back(ss);
        return;
      }
      ss.push_back(nums[k]);
      search(nums, ss, pos, k+1);
      ss.pop_back();
      search(nums, ss, pos, k+1);
    }
};

