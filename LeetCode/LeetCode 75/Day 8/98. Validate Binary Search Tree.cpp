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
    bool CheckBST(TreeNode* root, TreeNode* minn, TreeNode* maxx) {
        if (root == nullptr) return true;
        if (minn != nullptr && minn->val >= root->val || maxx != nullptr && maxx->val <= root->val)
            return false;

        return CheckBST(root->left, minn, root) && CheckBST(root->right, root, maxx);
    }
    bool isValidBST(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) return true;
        return CheckBST(root, nullptr, nullptr);
    }
};