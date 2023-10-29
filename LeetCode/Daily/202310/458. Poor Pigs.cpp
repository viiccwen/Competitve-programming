class Solution {
 public:
  int poorPigs(int buckets, int die, int test) {
    int y = (test / die) + 1;
    int z = y;
    int cnt = 1;

    if (buckets == 1) return 0;

    while (y < buckets) {
      y *= z;
      cnt++;
    }

    return cnt;
  }
};