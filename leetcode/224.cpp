class Solution {
public:
  int calculate(string s) {
    vector<int> vstack;
    int operand = 0, sign = 1, ans = 0;
    for (char c: s) {
      if (isdigit(c)) {
        operand = operand*10 + (c-'0');
      } else if (c == '+') {
        ans += sign*operand;
        operand = 0;
        sign = 1;
      } else if (c == '-') {
        ans += sign*operand;
        operand = 0; 
        sign = -1;
      } else if (c == '(') {
        vstack.push_back(ans);
        vstack.push_back(sign);
        ans = 0;
        sign = 1;
      } else if (c == ')') {
        ans += sign*operand;
        operand = 0;
        ans *= vstack.back(); vstack.pop_back();
        ans += vstack.back(); vstack.pop_back();
      }
    }
    return ans + (sign*operand);      
  }
}; 
