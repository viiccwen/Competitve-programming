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
    int sum = 0;
    void Traversal(TreeNode* node, int &low, int &high) {
        if(node == nullptr) return;

        int data = node->val;
        
        if(data >= low && data <= high) {
            sum += data;
            Traversal(node->left, low, high);
            Traversal(node->right, low, high);
        }
        else if(data < low) Traversal(node->right, low, high);
        
        else Traversal(node->left, low, high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        Traversal(root, low, high);
        return sum;
    }
};