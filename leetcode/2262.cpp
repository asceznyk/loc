typedef long long ll;

class Solution {
public:
  ll appealSum(string s) {
    int n = s.length();
    vector<ll> freq(26);
    vector<int> last(26, -1);
    ll ans = 0LL;
    for (int i = 0; i < n; i++) {
      ll csum = 0;
      char c = s[i]-'a';
      last[c] = i;
      for (int k = 0; k < 26; k++) {
        freq[k] += 1 + last[k]; 
        csum += freq[k];
      };
      ans = csum;
    }
    return ans;
  }
};


