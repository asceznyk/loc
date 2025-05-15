class Solution {
public:
  unordered_map<TreeNode* ,vector<TreeNode*>> adjList;
  void makeGraph(TreeNode* curr) {
    if (curr == nullptr) return;
    if (curr->left != nullptr) {
      adjList[curr].push_back(curr->left);
      adjList[curr->left].push_back(curr);
    }
    if (curr->right != nullptr) {
      adjList[curr].push_back(curr->right);
      adjList[curr->right].push_back(curr);
    } 
    makeGraph(curr->left);
    makeGraph(curr->right);
  }
  void markPairs(
    TreeNode*start, TreeNode* cur, TreeNode* par, int d, int distance,
    unordered_map<TreeNode*,bool>& leaves, unordered_map<TreeNode*,int>& dists
  ) {
    if (d > distance) return;
    if (leaves.find(cur) != leaves.end() && d > 0) {
      dists[start]++;
      return;
    } 
    for (auto& child: adjList[cur]) {
      if (child == par) continue;
      markPairs(start, child, cur, d+1, distance, leaves, dists);
    }
  }
  int countPairs(TreeNode* root, int distance) {
    adjList = {};
    makeGraph(root);
    unordered_map<TreeNode*,bool> leaves;
    for(auto& p: adjList) {
      if (p.first == root || p.second.size() > 1) continue;
      leaves[p.first] = true;
    }
    unordered_map<TreeNode*,int> dists;
    for (auto& p: leaves) {
      dists[p.first] = 0;
      markPairs(p.first, p.first, nullptr, 0, distance, leaves, dists);
    }
    int res = 0;
    for (auto& p: dists) res += p.second;
    return res/2;
  }
};

