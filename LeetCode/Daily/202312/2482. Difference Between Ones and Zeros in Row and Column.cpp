class Solution {
 public:
  vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> diff(n, vector<int>(m));
    vector<int> onesRow(n, 0);
    vector<int> zerosRow(n, 0);
    vector<int> onesCol(m, 0);
    vector<int> zerosCol(m, 0);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j]) {
          onesRow[i]++;
          onesCol[j]++;
        } else {
          zerosRow[i]++;
          zerosCol[j]++;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        diff[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
      }
    }

    return diff;
  }
};