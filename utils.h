#include <iostream>
#include <cassert>
#include <string>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
void printVector(vector<T>& v) {
  cout << "[" << " ";
  for(int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << "]" << '\n';
}

template <typename K, typename V>
void printHashMap(map<K,V>& umap) {
  cout << "{" << '\n';
  for(auto &it: umap)
    cout << "  " << it.first << ": " << it.second << '\n';
  cout << "}" << '\n';
}

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* buildSinglyLL(vector<int>& arr) {
  int n = arr.size();
  if(n == 0) return nullptr;
  ListNode* node = new ListNode(arr[0]);
  ListNode* head = node;
  for (int i = 1; i < n; i++) {
    node->next = new ListNode(arr[i]);
    node = node->next; 
  }
  return head;
}

void catLL(ListNode* head) {
  while (head != nullptr) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "NULL \n";
}

TreeNode* buildBinaryTree(vector<int>& arr, int arb) {
  int n = arr.size();
  if (n <= 0) return nullptr;
  int i = 0;
  TreeNode* root = new TreeNode(arr[i]);
  deque<TreeNode*> dq = {root};
  while (dq.size() != 0) {
    TreeNode* node = dq.front();
    dq.pop_front();
    if (node == nullptr) continue;
    int l = (2*i)+1, r = (2*i)+2;
    if (l <= n-1 && arr[l] != arb) {
      node->left = new TreeNode(arr[l]);
      dq.push_back(node->left);
    }
    if (r <= n-1 && arr[r] != arb) {
      node->right = new TreeNode(arr[r]);
      dq.push_back(node->right);
    }
    i++;
  }
  return root;
}

string traverseBinaryTree(TreeNode* root) {
  string visited = "";
  vector<pair<TreeNode*,int>> vstack = {{root, 0}};
  while (vstack.size() != 0) {
    pair<TreeNode*,int> p = vstack.back();
    TreeNode* node = p.first;
    int depth = p.second;
    vstack.pop_back();
    if (node == nullptr) continue;
    string sdepth = "";
    int d = 0;
    while (d < depth) {
      sdepth += "-";
      d++;
    }
    visited += sdepth + to_string(node->val);
    vstack.push_back({node->right, depth+1});
    vstack.push_back({node->left, depth+1});
  }
  return visited;
}

