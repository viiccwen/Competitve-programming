class Solution {
 public:
  vector<string> buildArray(vector<int>& target, int n) {
    vector<string> res;

    int k = 1;
    for (int i = 0; i < target.size(); i++) {
      while (k < target[i]) {
        res.push_back("Push");
        res.push_back("Pop");
        k++;
      }
      res.push_back("Push");
      k++;
    }

    return res;
  }
};