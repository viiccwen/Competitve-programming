#define pii pair<int, int>
class Solution {
 public:
  bool IsReached(int sx, int sy, int fx, int fy, int t) {  // 1 3   3 7
    if (sx <= fx && sy > fy)
      swap(sy, fy);
    else if (sx > fx && sy <= fy)
      swap(sx, fx);
    else if (sx > fx && sy > fy) {
      swap(sx, fx);
      swap(sy, fy);
    }

    int delta_x = fx - sx;
    int delta_y = fy - sy;
    int step = 0;
    if (delta_x <= delta_y) {
      step = delta_x;
      int cur_x = sx + delta_x;
      int cur_y = sy + delta_x;
      if (cur_y > fy)
        step -= (cur_y - fy);
      else
        step += (fy - cur_y);
    } else {
      step = delta_y;
      int cur_x = sx + delta_y;
      int cur_y = sy + delta_y;
      if (cur_x > fx)
        step -= (cur_x - fx);
      else
        step += (fx - cur_x);
    }

    if (step > t)
      return false;
    else
      return true;
  }
  bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    if (sx == fx && sy == fy && t > 0) return t == 1 ? false : true;
    if (sx == fx) return abs(fy - sy) <= t ? true : false;
    if (fy == sy) return abs(fx - sx) <= t ? true : false;

    return IsReached(sy, sx, fy, fx, t);
  }
};