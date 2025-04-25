typedef long long ll;

class Solution {
public:
  int MOD = 1e9+7;
  int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    vector<vector<int>> employees(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
      employees[i][0] = speed[i];
      employees[i][1] = efficiency[i];
    }
    sort(employees.begin(), employees.end(),
      [](const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    });
    priority_queue<int> pq;
    ll ssum = 0;
    ll ans = 0;
    ll score = 0;
    for (int i = 0; i < k; i++) {
      int eSpeed = employees[i][0], eEff = employees[i][1];
      pq.push(-eSpeed);
      ssum += eSpeed;
      score = eEff*ssum;
      ans = max(ans, score);
    }
    for (int i = k; i < n; i++) {
      int eSpeed = employees[i][0], eEff = employees[i][1];
      int cSpeed = -pq.top();
      if(cSpeed < eSpeed) {
        pq.pop();
        pq.push(-eSpeed);
        ssum += (eSpeed - cSpeed);
      }
      score = eEff*ssum;
      ans = max(ans, score); 
    }
    return ans % MOD;
  }
};

