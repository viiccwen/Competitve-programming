class Solution {
 public:
  bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
    vector<int> target(n, 0);
    int root = -1;

    for (int i = 0; i < left.size(); i++) {
      if (left[i] != -1 && target[left[i]]++ == 1) return false;
      if (right[i] != -1 && target[right[i]]++ == 1) return false;
    }

    for (int i = 0; i < target.size(); i++)
      if (!target[i]) root = i;

    if (root == -1) return false;

    return dfs(left, right, root) == n;
  }

  int dfs(vector<int>& left, vector<int>& right, int root) {
    if (root == -1) return 0;

    return 1 + dfs(left, right, left[root]) + dfs(left, right, right[root]);
  }
};