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
    void CreateNode(TreeNode*& root, int val) {
        root = new TreeNode;
        root->val = val;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) CreateNode(root, val);
        else if (root->left == nullptr && val < root->val) CreateNode(root->left, val);
        else if (root->right == nullptr && val > root->val) CreateNode(root->right, val);
        else if (val > root->val) insertIntoBST(root->right, val);
        else insertIntoBST(root->left, val);
        return root;
    }
};