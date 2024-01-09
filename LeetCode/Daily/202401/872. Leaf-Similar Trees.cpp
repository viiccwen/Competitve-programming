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
    void Traversal(TreeNode* node, vector<int>& vec) {
        if(node == nullptr) return;

        if(node->left == nullptr && node->right == nullptr) {
            vec.emplace_back(node->val);
            return;
        }

        Traversal(node->left, vec); 
        Traversal(node->right, vec); 
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1, vec2;
        Traversal(root1, vec1);
        Traversal(root2, vec2);
        return (vec1 == vec2);
    }
};