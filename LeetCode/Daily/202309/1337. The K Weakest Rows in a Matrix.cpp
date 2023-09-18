class Solution {
 public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    int r = mat.size(), c = mat[0].size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> vec;
    for (int i = 0; i < r; i++) {
      int cnt = 0;
      for (int j = 0; j < c; j++) {
        if (mat[i][j]) cnt++;
      }
      pq.push({cnt, i});
    }
    while (k--) {
      vector<int> v = pq.top();
      pq.pop();
      vec.push_back(v[1]);
    }
    return vec;
  }
};