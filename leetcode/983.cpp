class Solution {
public:
  int n = 0, m = 0;
  vector<bool> mask = {0};
  int dfs(int day, vector<int>& costs, vector<int>& mem) {
    if (day >= m) return 0;
    while (!mask[day]) day++;
    if (mem[day] != -1) return mem[day];
    return mem[day] = min(
      costs[0] + dfs(day+1, costs, mem),
      min(
        costs[1] + dfs(day+7, costs, mem),
        costs[2] + dfs(day+30, costs, mem)
      )
    );
  }
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    mask = {0};
    n = days.size();
    m = days[n-1]+1;
    mask.resize(m);
    for (int day: days) mask[day] = true;
    vector<int> mem(m, -1);
    return dfs(days[0], costs, mem);
  }
};

