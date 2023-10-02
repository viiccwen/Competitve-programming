class Solution {
 public:
  int player_cnt[2] = {0, 0};

  void CountTurn(string& colors, char c, int pos) {
    int len = colors.size();

    for (int i = 0; i < len; i++) {
      int cnt = 0;
      if (colors[i] == c) {
        while (colors[i] == c) {
          cnt++;
          if (i + 1 < len && colors[i + 1] == c)
            i++;
          else
            break;
        }
        if (cnt >= 3) player_cnt[pos] += cnt - 2;
        cnt = 0;
      }
    }
  }
  bool winnerOfGame(string colors) {
    int len = colors.size();
    if (len < 3) return false;
    int alice_cnt = 0;
    int bob_cnt = 0;

    CountTurn(colors, 'A', 0);
    CountTurn(colors, 'B', 1);

    if (player_cnt[0] > player_cnt[1])
      return true;
    else
      return false;
  }
};