class Solution {
 public:
  string decodeAtIndex(string s, int k) {
    unsigned long long decodeLen = 0ULL;

    for (auto c : s) {
      if (isdigit(c))
        decodeLen *= (c - '0');
      else
        decodeLen++;
    }

    for (int i = s.size() - 1; i >= 0; i--) {
      if (isdigit(s[i])) {
        decodeLen /= (s[i] - '0');
        k %= decodeLen;
      } else {
        if (!k || decodeLen == k) return string("") + s[i];
        decodeLen--;
      }
    }

    return "";
  }
};

// leetleetcode