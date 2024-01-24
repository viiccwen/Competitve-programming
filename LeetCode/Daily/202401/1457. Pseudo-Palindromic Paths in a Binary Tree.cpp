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
    int total = 0;
    vector<int> digit;

    bool isPalindrome() {
        int odd = 0;
        for(int i=0; i<=9; ++i)
            if(digit[i] % 2 != 0) odd++;

        if(odd > 1) return false;
        return true;
    }
    void dfs(TreeNode* node) {
        if(node == nullptr) return;
        
        digit[node->val]++;
        
        if(node->left == nullptr && node->right == nullptr)
            if(isPalindrome()) total++;

        dfs(node->left);
        dfs(node->right);

        digit[node->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        digit.assign(10, 0);
        dfs(root);
        return total;
    }
};