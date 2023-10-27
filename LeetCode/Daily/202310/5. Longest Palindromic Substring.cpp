class Solution {
 public:
  int n, start = 0, maximum = 0;

  void check(string& s, int left, int right) {
    while (left >= 0 && right < n) {
      if (s[left] != s[right]) break;
      left--, right++;
    }

    int len = right - left - 1;

    if (len > maximum) start = left + 1, maximum = len;
  }
  string longestPalindrome(string s) {
    n = s.size();
    for (int mid = 0; mid < n; mid++) {
      check(s, mid, mid);
      check(s, mid, mid + 1);
    }

    return s.substr(start, maximum);
  }
};

/*

O(n^2)

class Solution {
public:
    bool check(vector<vector<bool>>& dp, int i, int j, string& s) {
        if(i == j) return dp[i][j] = true;

        if(j - i == 1)
            return (s[i] == s[j]) ? dp[i][j] = true : dp[i][j] = false;

        return (s[i] == s[j] && dp[i+1][j-1]) ? dp[i][j] = true : dp[i][j] =
false;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maximum = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int k=0;k<=n;k++) {
            for(int i=0,j=k;j<n;i++,j++) {
                check(dp, i, j, s);
                if(dp[i][j] && j - i + 1 > maximum) {
                    start = i;
                    maximum = j - i + 1;
                }
            }
        }

        return s.substr(start, maximum);
    }
};
*/