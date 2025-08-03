class Solution {
public:
  struct PointerHash {
    size_t operator()(const TreeNode* ptr) const {
      return hash<uintptr_t>{}(reinterpret_cast<uintptr_t>(ptr));
    }
  };
  int dfs(
    TreeNode* node,
    unordered_map<TreeNode*,int, PointerHash>& dp
  ) {
    if (node == nullptr) return 0;
    if (dp.count(node) > 0) return dp[node];
    int compVal = 0;
    if (node->left != nullptr)
      compVal += dfs(node->left->left, dp) + \
                 dfs(node->left->right, dp);
    if (node->right != nullptr)
      compVal += dfs(node->right->left, dp) + \
                 dfs(node->right->right, dp);
    return dp[node] = max(
      node->val + compVal, 
      dfs(node->left, dp) + dfs(node->right, dp)
    );
  }
  int rob(TreeNode* root) {
    unordered_map<TreeNode*, int, PointerHash> dp; 
    return dfs(root, dp);
  }
};

