class Solution {
 public:
  vector<int> getRow(int row) {
    vector<vector<int>> pascal(row + 1);

    for (int i = 0; i <= row; i++) {
      for (int j = 0; j < i + 1; j++) {
        if (j == 0 || j == i)
          pascal[i].push_back(1);
        else
          pascal[i].push_back(pascal[i - 1][j - 1] + pascal[i - 1][j]);
      }
    }

    return pascal[row];
  }
};
