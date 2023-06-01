/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;
    void preorderTraversal(Node* root) {
        ans.push_back(root->val);

        int num = root->children.size();

        for (int i = 0; i < num; i++)
            preorderTraversal(root->children[i]);

    }
    vector<int> preorder(Node* root) {
        if (root == nullptr) return {};
        ans.push_back(root->val);

        int num = root->children.size();

        for (int i = 0; i < num; i++)
            preorderTraversal(root->children[i]);

        return ans;
    }
};