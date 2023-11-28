class Solution {
 public:
  int numberOfWays(string corridor) {
    const int MOD = 1e9 + 7;
    long int answer = 1, sofa = 0;
    pair<int, int> pre = {-1, -1}, next = {-1, -1};
    auto head = corridor.begin();

    while (1) {
      auto cur = find(head, corridor.end(), 'S');
      int idx = cur - corridor.begin();

      if (cur == corridor.end())
        break;
      else {
        sofa++;
        if (pre.first == -1) {
          pre.first = idx;
        } else if (pre.second == -1) {
          pre.second = idx;
        } else if (next.first == -1) {
          next.first = idx;
        } else if (next.second == -1) {
          next.second = idx;
          answer = (answer * (next.first - pre.second)) % MOD;
          pre = next;
          next = {-1, -1};
        }

        head = cur + 1;
      }
    }

    return !sofa || sofa % 2 ? 0 : answer;
  }
};