class Solution {
 public:
  int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    int n = dist.size();
    vector<double> times(n);
    for (int i = 0; i < n; i++) {
      times[i] = static_cast<double>(dist[i]) / speed[i];
    }

    sort(times.begin(), times.end());

    for (int i = 0; i < n; i++)
      if (times[i] <= i) return i;

    return n;
  }
};