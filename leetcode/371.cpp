class Solution {
public:
  int getSum(int a, int b) {
    while(b) {
      int carry = a & b; 
      a ^= b;
      b = (carry & b) << 1;
    }
    return a;
  }
};
