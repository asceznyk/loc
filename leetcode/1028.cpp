class Solution {
public:
  TreeNode* recoverFromPreorder(string traversal) {
    vector<pair<int,int>> valDepths;
    string nval;
    int depth = 0;
    int n = traversal.length();
    for (int i = 0; i < n; i++) {
      if (traversal[i] == '-') depth++;
      else nval += traversal[i];
      if (i+1 < n && traversal[i] != '-' && traversal[i+1] == '-') {
        valDepths.push_back({stoi(nval), depth});
        nval = "";
        depth = 0;
      }
    }
    valDepths.push_back({stoi(nval), depth});
    TreeNode* root = new TreeNode(valDepths[0].first);
    vector<pair<TreeNode*,int>> vstack = {{root, 0}};
    for (int i = 1; i < valDepths.size(); i++) {
      int val = valDepths[i].first, cur = valDepths[i].second;
      TreeNode* node = vstack.back().first;
      int depth = vstack.back().second;
      if (cur > depth) {
        node->left = new TreeNode(val);
        vstack.push_back({node->left, cur});
      } else {
        while (depth >= cur) {
          vstack.pop_back();
          node = vstack.back().first;
          depth = vstack.back().second;
        }
        node->right = new TreeNode(val);
        vstack.push_back({node->right, cur});
      }
    }
    return root;
  }
};

