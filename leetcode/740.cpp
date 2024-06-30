class Solution {
public:
  int deleteAndEarn(vector<int>& nums) {
    map<int,int> nmap;
    for(auto x: nums) {
      if(nmap.find(x) != nmap.end()) nmap[x]++;
      else nmap[x] = 1;
    }
    vector<int> uniq;
    for(auto& e: nmap) uniq.push_back(e.first);
    int u = uniq.size();
    vector<int> dp(u+1, 0);
    for(int i = u-1; i > -1; i--) {
      int x = uniq[i];
      int j = i+1;
      if(j < u && uniq[j] == x+1) j++;
      dp[i] = max((nmap[x]*x)+dp[j], dp[i+1]);
    }
    return dp[0];
  }
};

