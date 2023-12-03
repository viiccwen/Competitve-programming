class Solution {
 public:
  int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int time = 0;

    for (int i = 1; i < points.size(); i++) {
      int delta_x = abs(points[i][0] - points[i - 1][0]);
      int delta_y = abs(points[i][1] - points[i - 1][1]);
      time += max(delta_x, delta_y);
    }

    return time;
  }
};