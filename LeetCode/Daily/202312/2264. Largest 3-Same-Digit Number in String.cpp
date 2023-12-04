class Solution {
 public:
  bool Find(string &num, string &substr) {
    for (int i = 0; i < num.size() - 1; i++) {
      if (num.substr(i, 3) == substr) return true;
    }
    return false;
  }

  string largestGoodInteger(string num) {
    vector<string> mp = {"999", "888", "777", "666", "555",
                         "444", "333", "222", "111", "000"};

    for (auto substr : mp) {
      if (Find(num, substr)) return substr;
    }

    return "";
  }
};