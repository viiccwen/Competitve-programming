/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxx = 0;
    void dfs(TreeNode* root, int level) {
        maxx = max(maxx, level);
        if (root->left != nullptr) dfs(root->left, level + 1);
        if (root->right != nullptr) dfs(root->right, level + 1);
    }
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return maxx;
        dfs(root, maxx + 1);
        return maxx;
    }
};