class Solution {
 public:
  bool backspaceCompare(string s, string t) {
    string a = "", b = "";

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '#' && a.size() > 0)
        a.pop_back();
      else if (isalnum(s[i]))
        a += s[i];
    }

    for (int i = 0; i < t.size(); i++) {
      if (t[i] == '#' && b.size() > 0)
        b.pop_back();
      else if (isalnum(t[i]))
        b += t[i];
    }

    return a == b;
  }
};