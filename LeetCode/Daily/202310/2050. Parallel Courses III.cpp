class Solution {
 public:
  int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    unordered_map<int, vector<int>> graph;
    vector<int> in_deg(n + 1, 0);

    for (auto course : relations) {
      graph[course[0]].push_back(course[1]);
      in_deg[course[1]]++;
    }

    vector<int> dp = time;
    dp.insert(dp.begin(), 0);
    queue<int> q;
    for (int i = 1; i <= n; i++)
      if (!in_deg[i]) q.push(i);

    while (!q.empty()) {
      int course = q.front();
      q.pop();
      for (auto next : graph[course]) {
        dp[next] = max(dp[next], dp[course] + time[next - 1]);
        in_deg[next]--;
        if (!in_deg[next]) q.push(next);
      }
    }

    return *max_element(dp.begin(), dp.end());
  }
};

/*
1 3
2 3
*/