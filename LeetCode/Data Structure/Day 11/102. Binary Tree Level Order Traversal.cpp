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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<int>> ans;
        vector<int> v;
        queue<TreeNode*> q;
        TreeNode* node;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                node = q.front();
                v.push_back(node->val);
                q.pop();
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            ans.push_back(v);
            v.clear();
        }

        return ans;
    }
};