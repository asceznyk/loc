class Solution {
public:
  vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
  bool dfs(
    vector<vector<char>>& board, string word, int i, int j, int k
  ) {
    if(word.length() == k) return true;
    bool res = false;
    board[i][j] = '#';
    for(int d = 0; d < dirs.size(); d++) {
      int di = i+dirs[d][0], dj = j+dirs[d][1];
      if(
        di >= 0 && di <= board.size()-1 && 
        dj >= 0 && dj <= board[0].size()-1 &&
        word[k] == board[di][dj]
      ) res |= dfs(board, word, di, dj, k+1);
    }
    board[i][j] = word[k-1];
    return res;
  }
  bool exist(vector<vector<char>>& board, string word) {
    vector<int> bChars(58, 0);
    vector<int> wChars(58, 0);
    for(auto c: word)
      wChars[c-'A'] = 1;
    for(auto v: board)
      for(auto c: v) bChars[c-'A'] = 1;
    for(auto c: word)
      if(!bChars[c-'A']) return false;
    for(int i = 0; i < board.size(); i++) {
      for(int j = 0; j < board[i].size(); j++) {
        if(board[i][j] != word[0]) continue;
        if(dfs(board, word, i, j, 1)) return true;
      }
    }
    return false;
  }
};



