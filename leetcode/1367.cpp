class Solution {
public:
  bool findPath(TreeNode* node, ListNode* curr) {
    if (curr == nullptr) return true;
    if (node == nullptr) return false;
    if (node->val == curr->val)
      return findPath(node->left, curr->next) || findPath(node->right, curr->next);
    return false;
  }
  bool isSubPath(ListNode* head, TreeNode* root) {
    if (root == nullptr) return false;
    bool res = findPath(root, head);
    if (res) return res;
    return isSubPath(head, root->left) || isSubPath(head, root->right);
  }
};


