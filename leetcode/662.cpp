typedef unsigned long long ull;

class Solution {
public:
  void dfs(TreeNode* node, int d, ull i, map<int,pair<ull,ull>>& visited) {
    if (node == nullptr) return;
    if (visited.size() == d) {
      pair<ull,ull> newPair = {i,i};
      visited[d] = newPair;
    }
    visited[d].second = i;
    dfs(node->left, d+1, ((2*i)+1)-d, visited);
    dfs(node->right, d+1, ((2*i)+2)-d, visited);
  }
  int widthOfBinaryTree(TreeNode* root) {
    map<int,pair<ull,ull>> visited;
    dfs(root, 0, 0, visited);
    ull maxWidth = 0;
    for (auto& p: visited) {
      int k = p.first;
      pair<ull,ull> v = p.second;
      maxWidth = max(maxWidth, v.second-v.first+1);
    }
    return (int)maxWidth;
  }
};

