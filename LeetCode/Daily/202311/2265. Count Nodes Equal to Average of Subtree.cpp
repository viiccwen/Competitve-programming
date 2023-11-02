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
  pair<int, int> backtracking(TreeNode* node, int& sum) {
    if (node == nullptr) return {0, 0};

    auto [Lsum, Lcnt] = backtracking(node->left, sum);
    auto [Rsum, Rcnt] = backtracking(node->right, sum);

    int cur_sum = node->val + Lsum + Rsum;
    int cur_cnt = 1 + Lcnt + Rcnt;

    if (cur_sum / cur_cnt == node->val) sum++;

    return {cur_sum, cur_cnt};
  }
  int averageOfSubtree(TreeNode* root) {
    int sum = 0;
    backtracking(root, sum);
    return sum;
  }
};