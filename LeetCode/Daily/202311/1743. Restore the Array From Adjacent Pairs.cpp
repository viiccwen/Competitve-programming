class Solution {
 public:
  void dfs(unordered_map<int, vector<int>>& mp, int cur, set<int>& visited,
           vector<int>& ans) {
    if (visited.find(cur) != visited.end()) return;
    ans.push_back(cur);
    visited.insert(cur);
    for (int x : mp[cur]) {
      dfs(mp, x, visited, ans);
    }
  }
  vector<int> restoreArray(vector<vector<int>>& ad) {
    unordered_map<int, vector<int>> mp;
    int n = ad.size();

    for (int i = 0; i < n; i++) {
      mp[ad[i][0]].push_back(ad[i][1]);
      mp[ad[i][1]].push_back(ad[i][0]);
    }

    int head;
    for (auto ite : mp) {
      if (ite.second.size() == 1) {
        head = ite.first;
        break;
      }
    }

    set<int> visited;
    vector<int> ans;
    dfs(mp, head, visited, ans);
    return ans;
  }
};