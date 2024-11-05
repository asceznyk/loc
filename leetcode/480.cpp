#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class Solution {
public:
  void eraseElem(pbds& oset, int v) {
    int r = oset.order_of_key(v);
    pbds::iterator it = oset.find_by_order(r);
    oset.erase(it);
  }
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> ans;
    pbds oset;
    for (int i = 0; i < nums.size(); i++) {
      oset.insert(nums[i]);
      if(oset.size() < k) continue;
      double a = 1.00000;
      int idx = k/2;
      if(k % 2 == 1) {
        a = *oset.find_by_order(idx);
      } else {
        double x = *oset.find_by_order(idx);
        double y = *oset.find_by_order(idx-1);
        a = (x+y) / 2.0;
      }
      ans.push_back(a*1.00000);
      eraseElem(oset, nums[i+1-k]);
    }
    return ans;
  }
};

