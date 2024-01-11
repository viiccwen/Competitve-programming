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
    void FindMinMax(TreeNode* node, int minn, int maxx, int& diff) {
        if(node == nullptr) return;

        diff = max(diff, max(abs(minn - node->val), abs(maxx - node->val)));
        minn = min(minn, node->val);
        maxx = max(maxx, node->val);
        FindMinMax(node->left, minn, maxx, diff);
        FindMinMax(node->right, minn, maxx, diff);
    }
    int maxAncestorDiff(TreeNode* root) {
        int minn = root->val, maxx = root->val;
        int diff = 0;
        
        FindMinMax(root, minn, maxx, diff);

        return diff;
    }
};