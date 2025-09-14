#include "../utils.h"
#include <numeric>

class Solution {
public:
  TreeNode* root = nullptr;
  void buildBSTs(
    TreeNode* node, int d, int n,
    vector<TreeNode*>& res, vector<int>& visited 
  ) {
    if (accumulate(visited.begin(), visited.end(), 0) == n) {
      string treeS = traverseBinaryTree(root);
      printf("treeS = %s\n", treeS.c_str());
      res.push_back(root);
      return;
    }
    if (node->val == 1) {
      for (int j = node->val+1; j < n+1; j++) {
        if (visited[j]) continue;
        visited[j] = 1;
        node->right = new TreeNode(j);
        buildBSTs(node->right, d+1, n, res, visited);
        node->right = nullptr;
        visited[j] = 0;
      }
    } else if (node->val == n) {
      for (int j = 1; j < node->val; j++) {
        if (visited[j]) continue;
        visited[j] = 1;
        node->left = new TreeNode(j);
        buildBSTs(node->left, d+1, n, res, visited);
        node->left = nullptr;
        visited[j] = 0;
      }
    } else {
      for (int j = 1; j < node->val; j++) {
        if (visited[j]) continue;
        visited[j] = 1;
        node->left = new TreeNode(j);
        buildBSTs(node->left, d, n, res, visited);
        for (int k = node->val+1; k < n+1; k++) {
          if (visited[k]) continue;
          visited[k] = 1;
          node->right = new TreeNode(k);
          buildBSTs(node->right, d, n, res, visited);
          node->right = nullptr;
          visited[k] = 0;
        }
        node->left = nullptr;
        visited[j] = 0;
      }
    }
  }
  vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> res;
    vector<int> visited(n+1);
    for (int i = 1; i < n+1; i++) {
      root = new TreeNode(i);
      visited[i] = 1;
      buildBSTs(root, 0, n, res, visited);
      visited[i] = 0;
      printf("---\n");
    }
    return res;
  }
};

int main() {
  Solution sol;
  sol.generateTrees(3);
  return 0;
}

