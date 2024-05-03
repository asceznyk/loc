int max(int a, int b) {
  return a > b ? a : b;
}

int maxProfit(int* prices, int pricesSize) {
  int mem[pricesSize+1][3];
  for(int i = 0; i < pricesSize+1; i++) {
    for(int k = 0; k < 3; k++) mem[i][k] = 0; 
  }
  for(int i = pricesSize-1; i > -1; i--) {
    for(int k = 0; k < 3; k++) {
      if(k == 1) mem[i][k] = max(mem[i+1][2]+prices[i], mem[i+1][k]);
      else if(k == 2) mem[i][k] = mem[i+1][0];
      else mem[i][k] = max(mem[i+1][1]-prices[i], mem[i+1][k]);
    }
  }
  return mem[0][0];
}
