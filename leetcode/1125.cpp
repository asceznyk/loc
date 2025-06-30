typedef long long ll;

class Solution {
public:
  int m = 0, n = 0;
  ll dfs(int mask, vector<int>& skillBits, vector<ll>& mem) {
    cout << bitset<16>(mask) << " " << "\n";
    if (mask == 0) return 0;
    if (mem[mask] != -1) return mem[mask];
    for (int i = 0; i < m; i++) {
      int subset = mask & ~skillBits[i];
      if (mask == subset) continue; //ensures no person is selected twice!
      ll subMask = dfs(subset, skillBits, mem) | (1LL << i);
      if (
        mem[mask] == -1 ||
        __builtin_popcountll(subMask) < __builtin_popcountll(mem[mask])
      ) mem[mask] = subMask;
    }
    return mem[mask];
  }
  vector<int> smallestSufficientTeam(
    vector<string>& reqSkills, vector<vector<string>>& people
  ) {
    m = people.size(), n = reqSkills.size();
    unordered_map<string, int> skillID;
    for (int j = 0; j < n; j++) skillID[reqSkills[j]] = j;
    vector<int> skillBits(m);
    for (int i = 0; i < m; i++) {
      for (string skill: people[i]) {
        skillBits[i] |= (1 << skillID[skill]);
      }
    }
    vector<ll> mem((1<<n), -1);
    ll ans = dfs((1<<n)-1, skillBits, mem);
    vector<int> res;
    for (int i = 0; i < m; i++) {
      if ((ans >> i) & 1) res.push_back(i);
    }
    return res;
  }
};


