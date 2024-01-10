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
    void ConstructGraph(TreeNode* node,unordered_map<int, vector<int>>& graph) {
        if(node == nullptr) return;

        if(node->left != nullptr) {
            graph[node->val].emplace_back(node->left->val);
            graph[node->left->val].emplace_back(node->val);
        }

        if(node->right != nullptr) {
            graph[node->val].emplace_back(node->right->val);
            graph[node->right->val].emplace_back(node->val);
        }

        ConstructGraph(node->left, graph);
        ConstructGraph(node->right, graph);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> graph;
        ConstructGraph(root, graph);

        queue<int> q;
        unordered_set<int> visited;
        int minute = -1;

        q.push(start);
        while(!q.empty()) {
            minute++;

            for(int i=q.size(); i>0; --i) {
                int cur = q.front(); q.pop();
                visited.insert(cur);
                for(auto adj : graph[cur]) {
                    if(visited.find(adj) == visited.end()) 
                        q.push(adj);
                }
            }
        }

        return minute;
    }
};