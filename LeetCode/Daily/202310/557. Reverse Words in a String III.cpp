class Solution {
 public:
  string reverseWords(string s) {
    string str = "", tmp = "";
    bool flag = false;
    for (auto c : s) {
      if (c == ' ') {
        reverse(tmp.begin(), tmp.end());
        if (!flag)
          str += tmp, flag = true;
        else
          str += " " + tmp;
        tmp.clear();
      } else
        tmp += c;
    }

    reverse(tmp.begin(), tmp.end());
    if (tmp != "") {
      if (!flag)
        str += tmp;
      else
        str += " " + tmp;
    }
    return str;
  }
};