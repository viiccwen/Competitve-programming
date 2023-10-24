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
  vector<int> largestValues(TreeNode* root) {
    vector<int> vec;
    queue<pair<int, TreeNode*>> q;
    if (root == nullptr) return {};

    q.push({0, root});
    int prev = 0;
    int maximum = INT_MIN;
    while (!q.empty()) {
      int level = q.front().first;
      TreeNode* cur = q.front().second;
      q.pop();

      if (prev != level) {
        vec.push_back(maximum);
        maximum = INT_MIN;
        prev = level;
      }

      maximum = max(maximum, cur->val);

      if (cur->left != nullptr) q.push({level + 1, cur->left});
      if (cur->right != nullptr) q.push({level + 1, cur->right});
    }

    vec.push_back(maximum);

    return vec;
  }
};