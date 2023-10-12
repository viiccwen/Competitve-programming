/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
 public:
  int idx = INT_MAX;
  int peak = -1;
  int len;
  void BinarySearch(bool lr, int target, MountainArray &mountainArr) {
    int left, right;

    if (!lr) {
      left = 0;
      right = peak;
    } else {
      left = peak + 1;
      right = len - 1;
    }

    while (left <= right) {
      int mid = (left + right) / 2;
      int val = mountainArr.get(mid);
      if (val == target) {
        idx = mid;
        return;
      } else if (val < target) {
        if (!lr)
          left = mid + 1;
        else
          right = mid - 1;
      } else if (val > target) {
        if (!lr)
          right = mid - 1;
        else
          left = mid + 1;
      }
    }
  }
  void FindPeak(MountainArray &mountainArr) {
    if (mountainArr.get(0) > mountainArr.get(1))
      peak = 0;
    else if (mountainArr.get(len - 1) > mountainArr.get(len - 2))
      peak = len - 1;

    if (peak == -1) {
      int left = 1;
      int right = len - 2;
      while (left <= right) {
        int mid = (left + right) / 2;
        int curr = mountainArr.get(mid);
        int prev = mountainArr.get(mid - 1);
        int next = mountainArr.get(mid + 1);
        if (curr > prev && curr > next) {
          peak = mid;
          return;
        } else if (curr > prev && curr < next)
          left = mid + 1;
        else
          right = mid - 1;
      }
    }
  }
  int findInMountainArray(int target, MountainArray &mountainArr) {
    len = mountainArr.length();

    FindPeak(mountainArr);

    BinarySearch(false, target, mountainArr);

    if (idx == INT_MAX)
      BinarySearch(true, target, mountainArr);
    else
      return idx;

    if (idx == INT_MAX) return -1;

    return idx;
  }
};