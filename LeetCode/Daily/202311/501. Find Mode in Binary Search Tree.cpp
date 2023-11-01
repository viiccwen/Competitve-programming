/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  unordered_map<int, int> mp;
  int maximum = INT_MIN;
  void Traversal(TreeNode* root) {
    if (root != nullptr) {
      mp[root->val]++;
      maximum = max(maximum, mp[root->val]);
    }

    if (root->left != nullptr) Traversal(root->left);
    if (root->right != nullptr) Traversal(root->right);
  }
  vector<int> findMode(TreeNode* root) {
    if (root != nullptr) {
      mp[root->val]++;
      maximum = max(maximum, mp[root->val]);
    }
    if (root->left != nullptr) Traversal(root->left);
    if (root->right != nullptr) Traversal(root->right);

    vector<int> v;
    for (auto [key, val] : mp) {
      if (maximum == val) v.push_back(key);
    }
    return v;
  }
};