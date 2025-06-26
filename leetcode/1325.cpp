class Solution {
public:
  bool dfs(TreeNode* node, int target) {
    if (node == nullptr) return false;
    if (node->left == nullptr && node->right == nullptr && node->val == target)
      return true;
    if (dfs(node->left, target)) node->left = nullptr;
    if (dfs(node->right, target)) node->right = nullptr;
    if (node->left == nullptr && node->right == nullptr && node->val == target)
      return true;
    return false;
  }
  TreeNode* removeLeafNodes(TreeNode* root, int target) {
    return dfs(root, target) ?  nullptr : root;
  }
};

