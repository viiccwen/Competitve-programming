class Solution {
 public:
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers,
                               vector<int>& people) {
    vector<int> start, end;

    for (auto& flower : flowers) {
      start.push_back(flower[0]);
      end.push_back(flower[1]);
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    vector<int> ans;

    for (auto p : people) {
      int started = upper_bound(start.begin(), start.end(), p) - start.begin();
      int ended = lower_bound(end.begin(), end.end(), p) - end.begin();
      ans.push_back(started - ended);
    }

    return ans;
  }
};